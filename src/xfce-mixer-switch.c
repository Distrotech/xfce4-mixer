/* Generated by GOB (v2.0.9) on Wed Jul 21 21:09:32 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 9

#define selfp (self->_priv)

#include "xfce-mixer-switch.h"

#include "xfce-mixer-switch-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 1 "mixer-switch.gob"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#line 31 "xfce-mixer-switch.c"

#line 7 "mixer-switch.gob"

#include <gtk/gtk.h>
#include "xfce-mixer-control.h"

#line 38 "xfce-mixer-switch.c"
/* self casting macros */
#define SELF(x) XFCE_MIXER_SWITCH(x)
#define SELF_CONST(x) XFCE_MIXER_SWITCH_CONST(x)
#define IS_SELF(x) XFCE_IS_MIXER_SWITCH(x)
#define TYPE_SELF XFCE_TYPE_MIXER_SWITCH
#define SELF_CLASS(x) XFCE_MIXER_SWITCH_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MIXER_SWITCH_GET_CLASS(x)

/* self typedefs */
typedef XfceMixerSwitch Self;
typedef XfceMixerSwitchClass SelfClass;

/* here are local prototypes */
static void xfce_mixer_switch_class_init (XfceMixerSwitchClass * c) G_GNUC_UNUSED;
static void ___2_xfce_mixer_switch_value_changed (XfceMixerControl * pself) G_GNUC_UNUSED;
static void xfce_mixer_switch_init (XfceMixerSwitch * self) G_GNUC_UNUSED;
static void ___5_xfce_mixer_switch_vcname_changed (XfceMixerControl * pself) G_GNUC_UNUSED;

/* pointer to the class of our parent */
static XfceMixerControlClass *parent_class = NULL;

/* Short form macros */
#define self_changed_cb xfce_mixer_switch_changed_cb
#define self_new xfce_mixer_switch_new
GType
xfce_mixer_switch_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMixerSwitchClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mixer_switch_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMixerSwitch),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mixer_switch_init,
			NULL
		};

		type = g_type_register_static (XFCE_TYPE_MIXER_CONTROL, "XfceMixerSwitch", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMixerSwitch *)g_object_new(xfce_mixer_switch_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMixerSwitch * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMixerSwitch *
GET_NEW_VARG (const char *first, ...)
{
	XfceMixerSwitch *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMixerSwitch *)g_object_new_valist (xfce_mixer_switch_get_type (), first, ap);
	va_end (ap);
	return ret;
}

static void 
xfce_mixer_switch_class_init (XfceMixerSwitchClass * c G_GNUC_UNUSED)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::class_init"
	XfceMixerControlClass *xfce_mixer_control_class = (XfceMixerControlClass *)c;

	parent_class = g_type_class_ref (XFCE_TYPE_MIXER_CONTROL);

#line 29 "mixer-switch.gob"
	xfce_mixer_control_class->value_changed = ___2_xfce_mixer_switch_value_changed;
#line 58 "mixer-switch.gob"
	xfce_mixer_control_class->vcname_changed = ___5_xfce_mixer_switch_vcname_changed;
#line 118 "xfce-mixer-switch.c"
}
#undef __GOB_FUNCTION__
#line 44 "mixer-switch.gob"
static void 
xfce_mixer_switch_init (XfceMixerSwitch * self G_GNUC_UNUSED)
#line 124 "xfce-mixer-switch.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::init"
#line 7 "mixer-switch.gob"
	self->button = NULL;
#line 129 "xfce-mixer-switch.c"
 {
#line 45 "mixer-switch.gob"

		self->button = GTK_CHECK_BUTTON (gtk_check_button_new ());
		gtk_widget_show (GTK_WIDGET (self->button));
		gtk_box_pack_start (GTK_BOX (self), GTK_WIDGET (self->button), FALSE, FALSE, 0);
		g_signal_connect_swapped (G_OBJECT (self->button), "toggled", 
			G_CALLBACK (self_changed_cb), self);
	
#line 139 "xfce-mixer-switch.c"
 }
}
#undef __GOB_FUNCTION__


#line 15 "mixer-switch.gob"
void 
xfce_mixer_switch_changed_cb (XfceMixerSwitch * self, gpointer userdata)
#line 148 "xfce-mixer-switch.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::changed_cb"
#line 15 "mixer-switch.gob"
	g_return_if_fail (self != NULL);
#line 15 "mixer-switch.gob"
	g_return_if_fail (XFCE_IS_MIXER_SWITCH (self));
#line 155 "xfce-mixer-switch.c"
{
#line 16 "mixer-switch.gob"
	
		gboolean b;
		char c[2];
		c[1] = 0;
		b = gtk_toggle_button_get_active (
			GTK_TOGGLE_BUTTON (self->button)
		);

		c[0] = b ? '1' : '0';

		g_object_set (G_OBJECT (self), "value", c, NULL);
	}}
#line 170 "xfce-mixer-switch.c"
#undef __GOB_FUNCTION__

#line 29 "mixer-switch.gob"
static void 
___2_xfce_mixer_switch_value_changed (XfceMixerControl * pself G_GNUC_UNUSED)
#line 176 "xfce-mixer-switch.c"
#define PARENT_HANDLER(___pself) \
	{ if(XFCE_MIXER_CONTROL_CLASS(parent_class)->value_changed) \
		(* XFCE_MIXER_CONTROL_CLASS(parent_class)->value_changed)(___pself); }
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::value_changed"
#line 29 "mixer-switch.gob"
	g_return_if_fail (pself != NULL);
#line 29 "mixer-switch.gob"
	g_return_if_fail (XFCE_IS_MIXER_CONTROL (pself));
#line 186 "xfce-mixer-switch.c"
{
#line 31 "mixer-switch.gob"
	
		gchar *s;
                Self *self;
		gboolean b;
                self = SELF (pself);

                s = XFCE_MIXER_CONTROL (self)->value;
		b = (s && (s[0] == '1'));
		gtk_toggle_button_set_active (
			GTK_TOGGLE_BUTTON (self->button), b
		);
	}}
#line 201 "xfce-mixer-switch.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER


#line 53 "mixer-switch.gob"
XfceMixerControl * 
xfce_mixer_switch_new (void)
#line 209 "xfce-mixer-switch.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::new"
{
#line 54 "mixer-switch.gob"
	
		return XFCE_MIXER_CONTROL(GET_NEW);
	}}
#line 217 "xfce-mixer-switch.c"
#undef __GOB_FUNCTION__

#line 58 "mixer-switch.gob"
static void 
___5_xfce_mixer_switch_vcname_changed (XfceMixerControl * pself G_GNUC_UNUSED)
#line 223 "xfce-mixer-switch.c"
#define PARENT_HANDLER(___pself) \
	{ if(XFCE_MIXER_CONTROL_CLASS(parent_class)->vcname_changed) \
		(* XFCE_MIXER_CONTROL_CLASS(parent_class)->vcname_changed)(___pself); }
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Switch::vcname_changed"
#line 58 "mixer-switch.gob"
	g_return_if_fail (pself != NULL);
#line 58 "mixer-switch.gob"
	g_return_if_fail (XFCE_IS_MIXER_CONTROL (pself));
#line 233 "xfce-mixer-switch.c"
{
#line 60 "mixer-switch.gob"
	
		Self *self;
		char *sanename;

		self = SELF (pself);
		PARENT_HANDLER (pself);

		sanename = xfce_mixer_control_calc_sanename (pself);
		gtk_button_set_label (GTK_BUTTON (self->button), sanename);
		g_free (sanename);
        }}
#line 247 "xfce-mixer-switch.c"
#undef __GOB_FUNCTION__
#undef PARENT_HANDLER