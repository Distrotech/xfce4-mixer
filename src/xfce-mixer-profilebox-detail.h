/* Generated by GOB (v2.0.6)   (do not edit directly) */

#include <glib.h>
#include <glib-object.h>
#ifndef __XFCE_MIXER_PROFILEBOX_DETAIL_H__
#define __XFCE_MIXER_PROFILEBOX_DETAIL_H__

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



#include <gtk/gtk.h>
#include "vc.h"
#include "xfce-mixer-profile.h"


/*
 * Type checking and casting macros
 */
#define XFCE_TYPE_MIXER_PROFILEBOX_DETAIL	(xfce_mixer_profilebox_detail_get_type())
#define XFCE_MIXER_PROFILEBOX_DETAIL(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_profilebox_detail_get_type(), XfceMixerProfileboxDetail)
#define XFCE_MIXER_PROFILEBOX_DETAIL_CONST(obj)	G_TYPE_CHECK_INSTANCE_CAST((obj), xfce_mixer_profilebox_detail_get_type(), XfceMixerProfileboxDetail const)
#define XFCE_MIXER_PROFILEBOX_DETAIL_CLASS(klass)	G_TYPE_CHECK_CLASS_CAST((klass), xfce_mixer_profilebox_detail_get_type(), XfceMixerProfileboxDetailClass)
#define XFCE_IS_MIXER_PROFILEBOX_DETAIL(obj)	G_TYPE_CHECK_INSTANCE_TYPE((obj), xfce_mixer_profilebox_detail_get_type ())

#define XFCE_MIXER_PROFILEBOX_DETAIL_GET_CLASS(obj)	G_TYPE_INSTANCE_GET_CLASS((obj), xfce_mixer_profilebox_detail_get_type(), XfceMixerProfileboxDetailClass)

/*
 * Main object structure
 */
#ifndef __TYPEDEF_XFCE_MIXER_PROFILEBOX_DETAIL__
#define __TYPEDEF_XFCE_MIXER_PROFILEBOX_DETAIL__
typedef struct _XfceMixerProfileboxDetail XfceMixerProfileboxDetail;
#endif
struct _XfceMixerProfileboxDetail {
	GtkVBox __parent__;
	/*< private >*/
	GtkEntry * detail_name_entry; /* protected */
	GtkScrolledWindow * detail_sw; /* protected */
	GtkBox * detail_box; /* protected */
	GtkTreeView * detail_tv; /* protected */
	GtkTreeStore * detail_model; /* protected */
	gboolean dofill; /* protected */
	XfceMixerProfile * profile; /* protected */
	gchar * valids; /* protected */
};

/*
 * Class definition
 */
typedef struct _XfceMixerProfileboxDetailClass XfceMixerProfileboxDetailClass;
struct _XfceMixerProfileboxDetailClass {
	GtkVBoxClass __parent__;
};


/*
 * Public methods
 */
GType	xfce_mixer_profilebox_detail_get_type	(void);
void 	xfce_mixer_profilebox_detail_set_profile	(XfceMixerProfileboxDetail * self,
					XfceMixerProfile * p);
void 	xfce_mixer_profilebox_detail_clear	(XfceMixerProfileboxDetail * self);
gchar const * 	xfce_mixer_profilebox_detail_get_name	(XfceMixerProfileboxDetail * self);
void 	xfce_mixer_profilebox_detail_filln	(XfceMixerProfileboxDetail * self,
					char const * pname);
void 	xfce_mixer_profilebox_detail_each_vccache_cb	(XfceMixerProfileboxDetail * self,
					volcontrol_t * vci);
XfceMixerProfileboxDetail * 	xfce_mixer_profilebox_detail_new	(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
