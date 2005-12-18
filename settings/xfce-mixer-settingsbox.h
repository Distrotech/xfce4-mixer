/* Generated by GOB (v2.0.11)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MIXER_SETTINGSBOX_H__
#define __XFCE_MIXER_SETTINGSBOX_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



/* needs modified gob2 that adds config.h first */
#include <gtk/gtk.h>
#include <libxfce4util/libxfce4util.h>
#include <libxfcegui4/xfce_framebox.h>
#include <libxfce4mcs/mcs-manager.h>


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
	/*< public >*/
	McsManager * manager;
	/*< private >*/
	GtkWidget * dev_frame; /* protected */
	GtkLabel * dev_label; /* protected */
	GtkWidget * useful_frame; /* protected */
	GtkTreeView * useful_tv; /* protected */
	GtkTreeStore * useful_model; /* protected */
	GtkScrolledWindow * useful_sc; /* protected */
	GtkOptionMenu * devlist_om; /* protected */
	GtkBox * cols; /* protected */
	GtkBox * right_box; /* protected */
	GList * device_lst; /* protected */
	gchar * sel_device; /* protected */
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
void 	xfce_mixer_settingsbox_load	(XfceMixerSettingsbox * self);
void 	xfce_mixer_settingsbox_save	(XfceMixerSettingsbox * self);
void 	xfce_mixer_settingsbox_devicelst_updated	(XfceMixerSettingsbox * self);
XfceMixerSettingsbox * 	xfce_mixer_settingsbox_new	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
