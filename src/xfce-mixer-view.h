/* Generated by GOB (v2.0.6)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MIXER_VIEW_H__
#define __XFCE_MIXER_VIEW_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include "xfce-mixer-control.h"
#include "xfce-mixer-control-factory.h"
#include "xfce-mixer-profile.h"
#include "disclosure-widget.h"



/*
 * Type checking and casting macros
 */
#define XFCE_TYPE_MIXER_VIEW	(xfce_mixer_view_get_type())
#define XFCE_MIXER_VIEW(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_view_get_type(), XfceMixerView)
#define XFCE_MIXER_VIEW_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_view_get_type(), XfceMixerView const)
#define XFCE_MIXER_VIEW_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), xfce_mixer_view_get_type(), XfceMixerViewClass)
#define XFCE_IS_MIXER_VIEW(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), xfce_mixer_view_get_type ())

#define XFCE_MIXER_VIEW_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), xfce_mixer_view_get_type(), XfceMixerViewClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_XFCE_MIXER_VIEW__
#define __TYPEDEF_XFCE_MIXER_VIEW__
typedef struct _XfceMixerView XfceMixerView;
#endif
struct _XfceMixerView {
	GtkVBox __parent__;
	/*< private >*/
	GtkWidget * swsliders; /* protected */
	GtkBox * sliders; /* protected */
	GtkTable * selects; /* protected */
	GtkTable * switches; /* protected */
	gint switches_r; /* protected */
	gint switches_c; /* protected */
	gint selects_r; /* protected */
	gint selects_c; /* protected */
	GtkWidget * disclosure; /* protected */
	GtkBox * vbox; /* protected */
	GtkBox * tables; /* protected */
	GList * controls; /* protected */
	t_mixer_control_factory_kind kind; /* protected */
	XfceMixerProfile * profile; /* protected */
};

/*
 * Class definition
 */
typedef struct _XfceMixerViewClass XfceMixerViewClass;
struct _XfceMixerViewClass {
	GtkVBoxClass __parent__;
	void (* init_containers) (XfceMixerView * self);
	void (* view_item_updated) (XfceMixerView * self, XfceMixerControl * c, t_mixer_profile_item * p);
	void (* view_cleared) (XfceMixerView * self);
	void (* profile_cleared) (XfceMixerView * self);
	void (* profile_item_updated) (XfceMixerView * self, t_mixer_profile_item * p);
};


/*
 * Public methods
 */
GType	xfce_mixer_view_get_type	(void);
XfceMixerView * 	xfce_mixer_view_new	(void);
GtkContainer * 	xfce_mixer_view_find_container	(XfceMixerView * self,
					gchar const * name);
void 	xfce_mixer_view_set_profile	(XfceMixerView * self,
					XfceMixerProfile * p);
XfceMixerProfile const * 	xfce_mixer_view_get_profile	(XfceMixerView * self);
void 	xfce_mixer_view_profile_cleared	(XfceMixerView * self);
void 	xfce_mixer_view_profile_item_updated	(XfceMixerView * self,
					t_mixer_profile_item * p);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
