/* Generated by GOB (v2.0.6)   (do not edit directly) */

#ifndef __XFCE_MIXER_PROFILEBOX_PRIVATE_H__
#define __XFCE_MIXER_PROFILEBOX_PRIVATE_H__

#include "xfce-mixer-profilebox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include "xfce-mixer-profilebox-detail.h"
#include "xfce-mixer-profile.h"

#line 6 "mixer-profilebox.gob"
#line 20 "xfce-mixer-profilebox-private.h"
void 	xfce_mixer_profilebox_sel_changed_cb	(XfceMixerProfilebox * self, GtkTreeSelection * sel);
gint 	xfce_mixer_profilebox_profile_pos	(XfceMixerProfilebox * self, gchar const * name);
gboolean 	xfce_mixer_profilebox_profile_exists	(XfceMixerProfilebox * self, gchar const * name);
void 	xfce_mixer_profilebox_row_inserted_cb	(XfceMixerProfilebox * self, GtkTreePath * path, GtkTreeIter * iter, GtkTreeModel * model);
void 	xfce_mixer_profilebox_row_deleted_cb	(XfceMixerProfilebox * self, GtkTreePath * path, GtkTreeModel * model);
void 	xfce_mixer_profilebox_rowcnt_updated_cb	(XfceMixerProfilebox * self);
void 	xfce_mixer_profilebox_profiles_updated	(XfceMixerProfilebox * self);
void 	xfce_mixer_profilebox_select_last	(XfceMixerProfilebox * self);
void 	xfce_mixer_profilebox_new_dlg	(XfceMixerProfilebox * self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
