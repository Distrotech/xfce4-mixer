#ifdef HAVE_CONFIG_H
#include <config.h>
#endif
#include <gtk/gtk.h>
#include "xfce-mixer-profile.h"
#include "xfce-mixer-window.h"
#include "vc.h"
#include "vcreg.inc"

GtkTooltips *tooltips;

int main(int argc, char * argv[])
{
	GtkWidget *mixer_window;

	VC_INIT;

	gtk_init (&argc, &argv);
	
	tooltips = gtk_tooltips_new ();
	
	if (argc >=2 && argv[1][0] != '-') {
		vc_set_device (argv[1]);
	}

	mixer_window = xfce_mixer_window_new ();
	xfce_mixer_profile_fill_defaults (XFCE_MIXER_WINDOW (mixer_window)->profile);
	
	g_signal_connect (G_OBJECT (mixer_window), "destroy", G_CALLBACK (gtk_main_quit), NULL);
	gtk_widget_show (GTK_WIDGET (mixer_window));
		
	gtk_main ();
	return 0;
}