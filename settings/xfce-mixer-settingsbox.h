/* Generated by GOB (v2.0.6)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MIXER_SETTINGSBOX_H__
#define __XFCE_MIXER_SETTINGSBOX_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include <libxfce4util/i18n.h>
#include <libxfcegui4/xfce_framebox.h>


/*
 * Type checking and casting macros
 */
#define XFCE_TYPE_MIXER_SETTINGSBOX	(xfce_mixer_settingsbox_get_type())
#define XFCE_MIXER_SETTINGSBOX(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_settingsbox_get_type(), XfceMixerSettingsbox)
#define XFCE_MIXER_SETTINGSBOX_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_settingsbox_get_type(), XfceMixerSettingsbox const)
#define XFCE_MIXER_SETTINGSBOX_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), xfce_mixer_settingsbox_get_type(), XfceMixerSettingsboxClass)
#define XFCE_IS_MIXER_SETTINGSBOX(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), xfce_mixer_settingsbox_get_type ())

#define XFCE_MIXER_SETTINGSBOX_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), xfce_mixer_settingsbox_get_type(), XfceMixerSettingsboxClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_XFCE_MIXER_SETTINGSBOX__
#define __TYPEDEF_XFCE_MIXER_SETTINGSBOX__
typedef struct _XfceMixerSettingsbox XfceMixerSettingsbox;
#endif
struct _XfceMixerSettingsbox {
	GtkVBox __parent__;
	/*< private >*/
	GtkWidget * dev_frame; /* protected */
	GtkLabel * dev_label; /* protected */
	GtkWidget * useful_frame; /* protected */
	GtkTreeView * useful_tv; /* protected */
	GtkTreeStore * useful_model; /* protected */
	GtkScrolledWindow * useful_sc; /* protected */
	GtkTreeStore * devlist_model; /* protected */
	GtkTreeView * devlist_tv; /* protected */
	GtkScrolledWindow * devlist_sc; /* protected */
	GtkBox * cols; /* protected */
	GtkBox * right_box; /* protected */
	GtkWidget * sep; /* protected */
	GList * device_lst; /* protected */
};

/*
 * Class definition
 */
typedef struct _XfceMixerSettingsboxClass XfceMixerSettingsboxClass;
struct _XfceMixerSettingsboxClass {
	GtkVBoxClass __parent__;
};


/*
 * Public methods
 */
GType	xfce_mixer_settingsbox_get_type	(void);
XfceMixerSettingsbox * 	xfce_mixer_settingsbox_new	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
