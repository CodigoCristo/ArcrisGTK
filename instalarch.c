//Créditos: 
// @Miqueas2020
// @nahuelwexd
// @Bourne_Again

// sudo GTK_THEME=Breeze:dark ./instalarch
// sudo GTK_THEME=Plata-Noir ./instalarch3

// breeze-gtk
// papirus-icon-theme 
// git add .
// git commit -m 'instalarch'
// git push -f origin master

// https://help.gnome.org/users/zenity/stable/

/*zenity --list  --checklist --height=500 --width=450 --title="$title" --text "You will need to know what model of NVIDIA graphics card you are using.\nFor NVIDIA 400 series and newer install nvidia and nvidia-libgl.\nFor 8000-9000 or 100-300 series install nvidia-304xx and nvidia-304xx-libgl.\n\nYour current graphics card is:\n$card\n\nSelect the NVIDIA drivers that you would like to install." --column "Select" --column "Driver" FALSE "nvidia nvidia-utils nvidia-settings" FALSE "nvidia-304xx nvidia-304xx-utils nvidia-settings" FALSE "nvidia-340xx nvidia-340xx-utils nvidia-settings" FALSE "nvidia-lts nvidia-settings nvidia-utils" FALSE "nvidia-340xx-lts nvidia-340xx-utils nvidia-settings" FALSE "nvidia-304xx-lts nvidia-304xx-utils nvidia-settings" FALSE "nvidia-dkms" FALSE "nvidia-340xx-dkms" FALSE "nvidia-304xx-dkms"
*/

//echo "[chaotic-aur]\nInclude = /etc/pacman.d/chaotic-mirrorlist" >> /etc/pacman.conf

#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gprintf.h>
#include <string.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gtk/gtkx.h>
#include <math.h>
#include <ctype.h>
#include <libintl.h>
#include <locale.h>
#include <sys/wait.h> 
#include <gdk-pixbuf/gdk-pixbuf.h>
#include <vte/vte.h>
#define _(String) gettext (String)
#define N_(String) String
#define Len(arr) (sizeof (arr) / sizeof ((arr)[0]))


#include "elementos.h"
#include "idioma.h"
#include "disco.h"
#include "discomanual.h"
#include "users.h"
#include "escritorios.h"
#include "programas.h"
#include "botonesSgtAnt.h"
#include "instalacion.h"








void appActivate(GtkApplication *app, gpointer data) {

elementos();

gtk_stack_set_transition_duration (stack, 500);
gtk_entry_set_visibility(GTK_ENTRY(entryencrypt),    		FALSE);
gtk_entry_set_visibility(GTK_ENTRY(entrypassuser),    		FALSE);
gtk_entry_set_visibility(GTK_ENTRY(entrypassconfirmuser),   FALSE);
gtk_entry_set_visibility(GTK_ENTRY(entrypassroot),    		FALSE);

/////////////////////////////////////////////////////////////////////////////////
//Inicio de botones stack
/////////////////////////////////////////////////////////////////////////////////
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 
/////////////////////////////////////////////////////////////////////////////////
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc2"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc3"), FALSE); 



char* arranquesistema;
g_spawn_command_line_sync ("sh bash/script.sh arranque", &arranquesistema, NULL, NULL, NULL);
gtk_label_set_label (arranque, arranquesistema);

char* arranquesistemamanual;
g_spawn_command_line_sync ("sh bash/script.sh arranquemanual", &arranquesistemamanual, NULL, NULL, NULL);
gtk_label_set_label (texdiskboot, arranquesistemamanual);

pixbuf = gdk_pixbuf_new_from_file("escritorio/tty.png", NULL);
imgscaled = gdk_pixbuf_scale_simple(pixbuf, 580, 340, GDK_INTERP_BILINEAR);
gtk_image_set_from_pixbuf(img, imgscaled);


discoseleccion();
users();
infomodulos();
terminal();



GtkCssProvider *cssProvider = gtk_css_provider_new();
gtk_css_provider_load_from_path(cssProvider, "styling.css", NULL);
gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                           GTK_STYLE_PROVIDER(cssProvider),
                           GTK_STYLE_PROVIDER_PRIORITY_USER);


gtk_builder_connect_signals(builder, NULL);
gtk_widget_show_all((GtkWidget*) window);
gtk_application_add_window(app, window);

}


int main (int argc, char **argv) {

  gtk_init (&argc, &argv);
  int status;
  app = gtk_application_new("com.github.ArcriS", G_APPLICATION_FLAGS_NONE);
  g_signal_connect(app, "activate", (GCallback) appActivate, NULL);
  status = g_application_run((GApplication*) app, argc, argv);
  g_object_unref(app);
  return status;
  
}

