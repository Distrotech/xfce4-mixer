/*  mcs client
 *
 *  Copyright (C) 2002 Jasper Huijsmans <huysmans@users.sourceforge.net>
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/


#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <ctype.h>
#include <stdio.h>
#ifdef HAVE_STDDEF_H
#include <stddef.h>
#endif
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif

#include <X11/Xlib.h>
#include <X11/Xatom.h>
#include <gdk/gdkx.h>

#include <libxfce4util/i18n.h>
#include <libxfce4mcs/mcs-client.h>
#include <libxfcegui4/libnetk.h>

#include "mcs_client.h"
#include "helpers_h.inc"
#include "delayer.inc"

static McsClient *client = NULL;
static delayer_t refresh_delayer = DELAYER_INIT;

#include "main.h"

/* callback functions */
static void
update_setting (const char *name, McsSetting * setting)
{
	delayer_restart (&refresh_delayer, 1000, (GSourceFunc) delayed_refresh_cb, (gpointer) name);

}

/* event handling */
static void
notify_cb (const char *name, const char *channel_name,
	   McsAction action, McsSetting * setting, void *data)
{
    if (g_ascii_strcasecmp (CHANNEL, channel_name))
	return;

    switch (action)
    {
	case MCS_ACTION_NEW:
	    /* fall through */
	case MCS_ACTION_CHANGED:
	    update_setting (name, setting);
	    break;
	case MCS_ACTION_DELETED:
	    /* We don't use this now. Perhaps revert to default? */
	    break;
    }
}

static GdkFilterReturn
client_event_filter (GdkXEvent * xevent, GdkEvent * event, gpointer data)
{
    if (mcs_client_process_event (client, (XEvent *) xevent))
	return GDK_FILTER_REMOVE;
    else
	return GDK_FILTER_CONTINUE;
}

static void
watch_cb (Window window, Bool is_start, long mask, void *cb_data)
{
    GdkWindow *gdkwin;

    gdkwin = gdk_window_lookup (window);

    if (is_start)
	gdk_window_add_filter (gdkwin, client_event_filter, NULL);
    else
	gdk_window_remove_filter (gdkwin, client_event_filter, NULL);
}

/* connecting and disconnecting */
void
mcs_watch_xfce_channel (void)
{
    Display *dpy = GDK_DISPLAY ();
    int screen = DefaultScreen (dpy);

    client = NULL;

    if (!mcs_client_check_manager (dpy, screen, "xfce-mcs-manager"))
	g_warning ("%s: MCS settings manager not running!", PACKAGE);
    else
	client = mcs_client_new (dpy, screen, notify_cb, watch_cb, NULL);

    if (!client)
    {
	g_warning ("%s: could not connect to settings manager", PACKAGE);

	/*xfce_warn (_("Settings manager not available"));*/

	return;
    }

    mcs_client_add_channel (client, CHANNEL);
}

void
mcs_stop_watch (void)
{
    if (client)
	mcs_client_destroy (client);

    client = NULL;
}

/* this function is exported to allow access to other channels */
void
mcs_dialog (const char *channel)
{
    if (!client)
	return;

    if (channel)
	mcs_client_show (GDK_DISPLAY (), DefaultScreen (GDK_DISPLAY ()),
			 channel);
    else
	mcs_client_show (GDK_DISPLAY (), DefaultScreen (GDK_DISPLAY ()),
			 CHANNEL);
}

/* TODO: call delayer_free */
