/* Generated by GOB (v2.0.6) on Wed Feb 11 19:25:01 2004
   (do not edit directly) */

/* End world hunger, donate to the World Food Programme, http://www.wfp.org */

#define GOB_VERSION_MAJOR 2
#define GOB_VERSION_MINOR 0
#define GOB_VERSION_PATCHLEVEL 6

#define selfp (self->_priv)

#include <string.h> /* memset() */

#include "xfce-mixer-prefbox.h"

#include "xfce-mixer-prefbox-private.h"

#ifdef G_LIKELY
#define ___GOB_LIKELY(expr) G_LIKELY(expr)
#define ___GOB_UNLIKELY(expr) G_UNLIKELY(expr)
#else /* ! G_LIKELY */
#define ___GOB_LIKELY(expr) (expr)
#define ___GOB_UNLIKELY(expr) (expr)
#endif /* G_LIKELY */

#line 1 "mixer-prefbox.gob"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#line 33 "xfce-mixer-prefbox.c"

#line 6 "mixer-prefbox.gob"

#include <gtk/gtk.h>
#include <libxfcegui4/xfce_framebox.h>
#include <libxfce4util/i18n.h>
#include "xfce-mixer-preferences.h"
#include "vc.h"
#include "xfce-mixer-cache-vc.h"
#include "xfce-mixer-pxml.h"
#include <panel/item_dialog.h>
#include <panel/plugins.h>

/* why is this deprecated when it is needed by combo ? O_o */
GtkWidget *gtk_list_item_new_with_label (const gchar *label);


#line 51 "xfce-mixer-prefbox.c"

#line 25 "mixer-prefbox.gob"

#include "string_option_menu.h"

#define FHELPERS1
#include "helpers.inc"

#include "stringlist.inc"


#line 63 "xfce-mixer-prefbox.c"
/* self casting macros */
#define SELF(x) XFCE_MIXER_PREFBOX(x)
#define SELF_CONST(x) XFCE_MIXER_PREFBOX_CONST(x)
#define IS_SELF(x) XFCE_IS_MIXER_PREFBOX(x)
#define TYPE_SELF XFCE_TYPE_MIXER_PREFBOX
#define SELF_CLASS(x) XFCE_MIXER_PREFBOX_CLASS(x)

#define SELF_GET_CLASS(x) XFCE_MIXER_PREFBOX_GET_CLASS(x)

/* self typedefs */
typedef XfceMixerPrefbox Self;
typedef XfceMixerPrefboxClass SelfClass;

/* here are local prototypes */
static void xfce_mixer_prefbox_class_init (XfceMixerPrefboxClass * c) G_GNUC_UNUSED;
static void ___real_xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self);
static void xfce_mixer_prefbox_init (XfceMixerPrefbox * self) G_GNUC_UNUSED;

/*
 * Signal connection wrapper macro shortcuts
 */
#define self_connect__device_changed(object,func,data)	xfce_mixer_prefbox_connect__device_changed((object),(func),(data))
#define self_connect_after__device_changed(object,func,data)	xfce_mixer_prefbox_connect_after__device_changed((object),(func),(data))
#define self_connect_data__device_changed(object,func,data,destroy_data,flags)	xfce_mixer_prefbox_connect_data__device_changed((object),(func),(data),(destroy_data),(flags))

enum {
	DEVICE_CHANGED_SIGNAL,
	LAST_SIGNAL
};

static guint object_signals[LAST_SIGNAL] = {0};

/* pointer to the class of our parent */
static GtkVBoxClass *parent_class = NULL;

/* Short form macros */
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define self_fill_defaults(args...) xfce_mixer_prefbox_fill_defaults(args)
#define self_fill_device_list(args...) xfce_mixer_prefbox_fill_device_list(args)
#define self_fill_master_list(args...) xfce_mixer_prefbox_fill_master_list(args)
#define self_find_name_by_master_i(args...) xfce_mixer_prefbox_find_name_by_master_i(args)
#define self_find_master_by_name(args...) xfce_mixer_prefbox_find_master_by_name(args)
#define self_device_changed(args...) xfce_mixer_prefbox_device_changed(args)
#define self_add_command_box(args...) xfce_mixer_prefbox_add_command_box(args)
#define self_device_changed_delayed_cb(args...) xfce_mixer_prefbox_device_changed_delayed_cb(args)
#define self_device_changed_cb(args...) xfce_mixer_prefbox_device_changed_cb(args)
#define self_new(args...) xfce_mixer_prefbox_new(args)
#define self_fill_preferences(args...) xfce_mixer_prefbox_fill_preferences(args)
#define self_save_preferences(args...) xfce_mixer_prefbox_save_preferences(args)
#endif /* __GNUC__ && !__STRICT_ANSI__ */

/* Short form pointers */
static void (* const self_fill_defaults) (XfceMixerPrefbox * self) = xfce_mixer_prefbox_fill_defaults;
static void (* const self_fill_device_list) (XfceMixerPrefbox * self) = xfce_mixer_prefbox_fill_device_list;
static void (* const self_fill_master_list) (XfceMixerPrefbox * self) = xfce_mixer_prefbox_fill_master_list;
static gchar * (* const self_find_name_by_master_i) (XfceMixerPrefbox * self, gint master_i) = xfce_mixer_prefbox_find_name_by_master_i;
static gint (* const self_find_master_by_name) (XfceMixerPrefbox * self, gchar const * name) = xfce_mixer_prefbox_find_master_by_name;
static void (* const self_device_changed) (XfceMixerPrefbox * self) = xfce_mixer_prefbox_device_changed;
static void (* const self_add_command_box) (XfceMixerPrefbox * self, Control * plugin) = xfce_mixer_prefbox_add_command_box;
static gboolean (* const self_device_changed_delayed_cb) (XfceMixerPrefbox * self) = xfce_mixer_prefbox_device_changed_delayed_cb;
static void (* const self_device_changed_cb) (XfceMixerPrefbox * self, GtkEditable * e) = xfce_mixer_prefbox_device_changed_cb;
static GtkWidget * (* const self_new) (Control * plugin) = xfce_mixer_prefbox_new;
static void (* const self_fill_preferences) (XfceMixerPrefbox * self, XfceMixerPreferences * p) = xfce_mixer_prefbox_fill_preferences;
static void (* const self_save_preferences) (XfceMixerPrefbox * self, XfceMixerPreferences * p) = xfce_mixer_prefbox_save_preferences;

GType
xfce_mixer_prefbox_get_type (void)
{
	static GType type = 0;

	if ___GOB_UNLIKELY(type == 0) {
		static const GTypeInfo info = {
			sizeof (XfceMixerPrefboxClass),
			(GBaseInitFunc) NULL,
			(GBaseFinalizeFunc) NULL,
			(GClassInitFunc) xfce_mixer_prefbox_class_init,
			(GClassFinalizeFunc) NULL,
			NULL /* class_data */,
			sizeof (XfceMixerPrefbox),
			0 /* n_preallocs */,
			(GInstanceInitFunc) xfce_mixer_prefbox_init,
		};

		type = g_type_register_static (GTK_TYPE_VBOX, "XfceMixerPrefbox", &info, (GTypeFlags)0);
	}

	return type;
}

/* a macro for creating a new object of our type */
#define GET_NEW ((XfceMixerPrefbox *)g_object_new(xfce_mixer_prefbox_get_type(), NULL))

/* a function for creating a new object of our type */
#include <stdarg.h>
static XfceMixerPrefbox * GET_NEW_VARG (const char *first, ...) G_GNUC_UNUSED;
static XfceMixerPrefbox *
GET_NEW_VARG (const char *first, ...)
{
	XfceMixerPrefbox *ret;
	va_list ap;
	va_start (ap, first);
	ret = (XfceMixerPrefbox *)g_object_new_valist (xfce_mixer_prefbox_get_type (), first, ap);
	va_end (ap);
	return ret;
}


static void
___finalize(GObject *obj_self)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::finalize"
	XfceMixerPrefbox *self = XFCE_MIXER_PREFBOX (obj_self);
	gpointer priv = self->_priv;
	if(G_OBJECT_CLASS(parent_class)->finalize) \
		(* G_OBJECT_CLASS(parent_class)->finalize)(obj_self);
#line 39 "mixer-prefbox.gob"
	if(self->master_lst) { ((*(void (*)(void *))stringlist_free)) (self->master_lst); self->master_lst = NULL; }
#line 181 "xfce-mixer-prefbox.c"
#define device_entry_delayer (self->_priv->device_entry_delayer)
#define VAR device_entry_delayer
	{
#line 46 "mixer-prefbox.gob"
	 delayer_free (VAR); }
#line 187 "xfce-mixer-prefbox.c"
	memset(&device_entry_delayer, 0, sizeof(device_entry_delayer));
#undef VAR
#undef device_entry_delayer
	g_free (priv);
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__

static void 
xfce_mixer_prefbox_class_init (XfceMixerPrefboxClass * c)
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::class_init"
	GObjectClass *g_object_class = (GObjectClass*) c;

	parent_class = g_type_class_ref (GTK_TYPE_VBOX);

	object_signals[DEVICE_CHANGED_SIGNAL] =
		g_signal_new ("device_changed",
			G_TYPE_FROM_CLASS (g_object_class),
			(GSignalFlags)(G_SIGNAL_RUN_FIRST | G_SIGNAL_ACTION),
			G_STRUCT_OFFSET (XfceMixerPrefboxClass, device_changed),
			NULL, NULL,
			g_cclosure_marshal_VOID__VOID,
			G_TYPE_NONE, 0);

#line 135 "mixer-prefbox.gob"
	c->device_changed = ___real_xfce_mixer_prefbox_device_changed;
#line 216 "xfce-mixer-prefbox.c"
	g_object_class->finalize = ___finalize;
	return;
	c = NULL;
	g_object_class = NULL;
}
#undef __GOB_FUNCTION__
#line 164 "mixer-prefbox.gob"
static void 
xfce_mixer_prefbox_init (XfceMixerPrefbox * self)
#line 226 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::init"
	self->_priv = g_new0 (XfceMixerPrefboxPrivate, 1);
#line 25 "mixer-prefbox.gob"
	self->master_lst = NULL;
#line 232 "xfce-mixer-prefbox.c"
#line 25 "mixer-prefbox.gob"
	self->_priv->device_entry_delayer = 0;
#line 235 "xfce-mixer-prefbox.c"
#line 46 "mixer-prefbox.gob"
	self->ic = NULL;
#line 238 "xfce-mixer-prefbox.c"
#line 46 "mixer-prefbox.gob"
	self->click_b = NULL;
#line 241 "xfce-mixer-prefbox.c"
#line 46 "mixer-prefbox.gob"
	self->plugin = NULL;
#line 244 "xfce-mixer-prefbox.c"
 {
#line 165 "mixer-prefbox.gob"

		GtkWidget *dentry;
		GtkWidget *item;

		gtk_box_set_spacing (GTK_BOX (self), 5);
		self->device_cb = GTK_COMBO (gtk_combo_new ());
		self->master_om = GTK_OPTION_MENU (gtk_option_menu_new ());


		gtk_container_set_border_width (GTK_CONTAINER (self), 5);
		gtk_box_pack_start (GTK_BOX (self), twocol_label ("Device:", GTK_WIDGET (self->device_cb)), FALSE, FALSE, 0);
		gtk_box_pack_start (GTK_BOX (self), twocol_label ("Wannabe Master:", GTK_WIDGET (self->master_om)), FALSE, FALSE, 0);

		gtk_box_pack_start (GTK_BOX (self), headline ("When clicked", &self->click_b), FALSE, FALSE, 0);


		gtk_entry_set_max_length (GTK_ENTRY (self->device_cb->entry), 50);

		gtk_combo_set_value_in_list (GTK_COMBO (self->device_cb), FALSE, TRUE);
		if (self->execu_cb)
			gtk_combo_set_value_in_list (GTK_COMBO (self->execu_cb), FALSE, TRUE);

		self_fill_device_list (self);

		emit self_device_changed (self);

		dentry = GTK_WIDGET (self->device_cb->entry);
		g_signal_connect_swapped (G_OBJECT (dentry), "changed", G_CALLBACK (self_device_changed_cb), self);

		if (self->execu_cb && g_find_program_in_path ("xfce4-mixer")) {
			item = gtk_list_item_new_with_label ("xfce4-mixer");
			gtk_widget_show (item);
			gtk_combo_set_item_string (GTK_COMBO (self->execu_cb), GTK_ITEM (item), "xfce4-mixer");
			gtk_container_add (GTK_CONTAINER (GTK_COMBO (self->execu_cb)->list), item);
		}
	
#line 283 "xfce-mixer-prefbox.c"
 }
	return;
	self = NULL;
}
#undef __GOB_FUNCTION__


#line 51 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_defaults (XfceMixerPrefbox * self)
#line 294 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_defaults"
#line 51 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 51 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 301 "xfce-mixer-prefbox.c"
{
#line 52 "mixer-prefbox.gob"
	
		command_options_set_command (self->ic, "xfce4-mixer", FALSE, TRUE);
		gtk_entry_set_text (GTK_ENTRY (self->device_cb->entry), "");
		emit self_device_changed (self);
	}}
#line 309 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 58 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_device_list (XfceMixerPrefbox * self)
#line 315 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_device_list"
#line 58 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 58 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 322 "xfce-mixer-prefbox.c"
{
#line 59 "mixer-prefbox.gob"
	
		GList *gl;

		gl = vc_get_device_list ();
		if (gl) {
			gtk_combo_set_popdown_strings (GTK_COMBO (self->device_cb), gl);
			vc_free_device_list (gl);
		} else {
			/* TODO: clear popdown list O_o */
			/* gtk_combo_set_popdown_strings (, NUL); issues warning */
		}
	}}
#line 337 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 72 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_master_list (XfceMixerPrefbox * self)
#line 343 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_master_list"
#line 72 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 72 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 350 "xfce-mixer-prefbox.c"
{
#line 73 "mixer-prefbox.gob"
	
		stringlist_free (self->master_lst);
		self->master_lst = NULL;
		xfce_mixer_cache_vc_foreach (master_enum_cb, &self->master_lst);

		fill_string_option_menu (self->master_om, self->master_lst);
	}}
#line 360 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 81 "mixer-prefbox.gob"
gchar * 
xfce_mixer_prefbox_find_name_by_master_i (XfceMixerPrefbox * self, gint master_i)
#line 366 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::find_name_by_master_i"
#line 81 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gchar * )0);
#line 81 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gchar * )0);
#line 373 "xfce-mixer-prefbox.c"
{
#line 82 "mixer-prefbox.gob"
	
		gint i;
		GList *g;
		gchar *s;

		if (master_i == -1)
			return NULL;

		i = 0;
		g = self->master_lst;
		while (g) {
			s = (gchar *)g->data;
			if (s) {
				if (i == master_i)
					return g_strdup (s);
			}

			g = g_list_next (g);
			++i;
		}
		return NULL;
	}}
#line 398 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 105 "mixer-prefbox.gob"
gint 
xfce_mixer_prefbox_find_master_by_name (XfceMixerPrefbox * self, gchar const * name)
#line 404 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::find_master_by_name"
#line 105 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gint )0);
#line 105 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gint )0);
#line 411 "xfce-mixer-prefbox.c"
{
#line 106 "mixer-prefbox.gob"
	
		gint i;
		gint master_i;
		GList *g;
		gchar *s;

		master_i = -1;
		if (!name) {
			return master_i;
		}

		i = 0;
		g = self->master_lst;

		while (g) {
			s = (gchar *)g->data;
			if (s) {
				if (g_str_equal (s, name))
					master_i = i;
			}

			g = g_list_next (g);
			++i;
		}

		return master_i;
	}}
#line 441 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 135 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self)
#line 447 "xfce-mixer-prefbox.c"
{
	GValue ___param_values[1];
	GValue ___return_val = {0};

#line 135 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 135 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 456 "xfce-mixer-prefbox.c"

	___param_values[0].g_type = 0;
	g_value_init (&___param_values[0], G_TYPE_FROM_INSTANCE (self));
	g_value_set_instance (&___param_values[0], (gpointer) self);

	g_signal_emitv (___param_values,
		object_signals[DEVICE_CHANGED_SIGNAL],
		0 /* detail */,
		&___return_val);

	g_value_unset (&___param_values[0]);
}
#line 135 "mixer-prefbox.gob"
static void 
___real_xfce_mixer_prefbox_device_changed (XfceMixerPrefbox * self)
#line 472 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed"
{
#line 137 "mixer-prefbox.gob"
	
		gint omi;
		gchar const *txt;
		gchar *master;

		txt = gtk_entry_get_text (GTK_ENTRY (self->device_cb->entry));
		if (txt)
			vc_set_device (txt);

		omi = gtk_option_menu_get_history (self->master_om);
		master = self_find_name_by_master_i (self, omi);

		self_fill_master_list (self);
		omi = -1;
		if (master) {
			omi = self_find_master_by_name (self, master);
			g_free (master);
		}

		/*if (omi == -1)
			omi = self_find_master (self);
		*/

		gtk_option_menu_set_history (self->master_om, omi);

	}}
#line 503 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__


#line 202 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_add_command_box (XfceMixerPrefbox * self, Control * plugin)
#line 510 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::add_command_box"
#line 202 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 202 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 517 "xfce-mixer-prefbox.c"
{
#line 203 "mixer-prefbox.gob"
	
		self->plugin = plugin;
		self->ic = create_command_options (NULL);
		self->execu_cb = NULL; /*self->ic->combo;*/
		/*self->execu_entry = self->ic->command_entry;*/
		self->startup_nf_c = GTK_CHECK_BUTTON (self->ic->sn_checkbutton);
		self->in_terminal_c = GTK_CHECK_BUTTON (self->ic->term_checkbutton);
		gtk_box_pack_start (GTK_BOX (self->click_b), GTK_WIDGET (self->ic->base), FALSE, FALSE, 0);
	}}
#line 529 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 213 "mixer-prefbox.gob"
gboolean 
xfce_mixer_prefbox_device_changed_delayed_cb (XfceMixerPrefbox * self)
#line 535 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed_delayed_cb"
#line 213 "mixer-prefbox.gob"
	g_return_val_if_fail (self != NULL, (gboolean )0);
#line 213 "mixer-prefbox.gob"
	g_return_val_if_fail (XFCE_IS_MIXER_PREFBOX (self), (gboolean )0);
#line 542 "xfce-mixer-prefbox.c"
{
#line 214 "mixer-prefbox.gob"
	
		/*printf ("delayed\n");*/
		emit self_device_changed (self);
		return FALSE;
	}}
#line 550 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 220 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_device_changed_cb (XfceMixerPrefbox * self, GtkEditable * e)
#line 556 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::device_changed_cb"
#line 220 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 220 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 563 "xfce-mixer-prefbox.c"
{
#line 221 "mixer-prefbox.gob"
	
		delayer_restart (
			&self->_priv->device_entry_delayer, 
			500, (GSourceFunc) (self_device_changed_delayed_cb), 
			self
		);
	}}
#line 573 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 229 "mixer-prefbox.gob"
GtkWidget * 
xfce_mixer_prefbox_new (Control * plugin)
#line 579 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::new"
{
#line 230 "mixer-prefbox.gob"
	
		GtkWidget *w;
		w = GTK_WIDGET (GET_NEW);
		xfce_mixer_prefbox_add_command_box (XFCE_MIXER_PREFBOX (w), plugin);
		return w;
	}}
#line 590 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 237 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_fill_preferences (XfceMixerPrefbox * self, XfceMixerPreferences * p)
#line 596 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::fill_preferences"
#line 237 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 237 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 603 "xfce-mixer-prefbox.c"
{
#line 238 "mixer-prefbox.gob"
	
		gint omi;
		gchar *s;
		if (!p) {
			self_fill_defaults (self);
			return;
		}

		command_options_set_command (self->ic, 
			nvl (p->execu, "xfce4-mixer"),
			p->in_terminal,
			p->startup_nf
		);

		gtk_entry_set_text (GTK_ENTRY (self->device_cb->entry), nvl (p->device, ""));

		g_object_get (G_OBJECT (p), "master", &s, NULL);
		omi = self_find_master_by_name (self, s);
		g_free (s);
		s = NULL;

		gtk_option_menu_set_history (self->master_om, omi);

		emit self_device_changed (self);
	}}
#line 631 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__

#line 264 "mixer-prefbox.gob"
void 
xfce_mixer_prefbox_save_preferences (XfceMixerPrefbox * self, XfceMixerPreferences * p)
#line 637 "xfce-mixer-prefbox.c"
{
#define __GOB_FUNCTION__ "Xfce:Mixer:Prefbox::save_preferences"
#line 264 "mixer-prefbox.gob"
	g_return_if_fail (self != NULL);
#line 264 "mixer-prefbox.gob"
	g_return_if_fail (XFCE_IS_MIXER_PREFBOX (self));
#line 644 "xfce-mixer-prefbox.c"
{
#line 265 "mixer-prefbox.gob"
	
		gint omi;
		gchar *execu;
		gchar const *device;
		gchar *master;
		gboolean startup_nf;
		gboolean in_terminal;

		if (!p)
			return;

		device = gtk_entry_get_text (GTK_ENTRY (self->device_cb->entry));
		emit self_device_changed (self);

		omi = gtk_option_menu_get_history (self->master_om);
		master = self_find_name_by_master_i (self, omi);

		command_options_get_command (self->ic, &execu, &in_terminal, &startup_nf);

		g_object_set (G_OBJECT (p),
			"device", device,
			"execu", execu,
			"master", master,
			"startup_nf", startup_nf,
			"in_terminal", in_terminal,
			NULL
		);

		if (execu)
			g_free (execu);

		if (master)
			g_free (master);
	}}
#line 681 "xfce-mixer-prefbox.c"
#undef __GOB_FUNCTION__


#if (!defined __GNUC__) || (defined __GNUC__ && defined __STRICT_ANSI__)
/*REALLY BAD HACK
  This is to avoid unused warnings if you don't call
  some method.  I need to find a better way to do
  this, not needed in GCC since we use some gcc
  extentions to make saner, faster code */
static void
___xfce_mixer_prefbox_really_bad_hack_to_avoid_warnings(void)
{
	((void (*)(void))GET_NEW_VARG)();
	((void (*)(void))self_fill_defaults)();
	((void (*)(void))self_fill_device_list)();
	((void (*)(void))self_fill_master_list)();
	((void (*)(void))self_find_name_by_master_i)();
	((void (*)(void))self_find_master_by_name)();
	((void (*)(void))self_device_changed)();
	((void (*)(void))self_add_command_box)();
	((void (*)(void))self_device_changed_delayed_cb)();
	((void (*)(void))self_device_changed_cb)();
	((void (*)(void))self_new)();
	((void (*)(void))self_fill_preferences)();
	((void (*)(void))self_save_preferences)();
	___xfce_mixer_prefbox_really_bad_hack_to_avoid_warnings();
}
#endif /* !__GNUC__ || (__GNUC__ && __STRICT_ANSI__) */

