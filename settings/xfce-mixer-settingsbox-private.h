/* Generated by GOB (v2.0.11)   (do not edit directly) */

#ifndef __XFCE_MIXER_SETTINGSBOX_PRIVATE_H__
#define __XFCE_MIXER_SETTINGSBOX_PRIVATE_H__

#include "xfce-mixer-settingsbox.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/* needs modified gob2 that adds config.h first */
#include <gtk/gtk.h>
#include <libxfce4util/libxfce4util.h>
#include <libxfcegui4/xfce_framebox.h>
#include <libxfce4mcs/mcs-manager.h>

#line 1 "mixer-settingsbox.gob"
#line 22 "xfce-mixer-settingsbox-private.h"
void 	xfce_mixer_settingsbox_device_changed_cb	(XfceMixerSettingsbox * self);
void 	xfce_mixer_settingsbox_reselect_device	(XfceMixerSettingsbox * self);
void 	xfce_mixer_settingsbox_fill_right_box	(XfceMixerSettingsbox * self);
void 	xfce_mixer_settingsbox_apply_right_box	(XfceMixerSettingsbox * self);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
