typedef struct { const gchar *name, *label; } CStore;
CStore dem[] = {
  { "escritorio/xfce4", "Xfce4" },
  { "escritorio/plasma", "KDE Plasma" },
  { "escritorio/gnome", "GNOME" },

};

CStore wmm[] = {
  { "escritorio/i3", "i3" },
  { "escritorio/awesome", "Awesome" },
  { "escritorio/qtile", "Qtile" },
};

void on_DERadioBtn_toggled () {
	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual"), TRUE); 
	gtk_combo_box_text_remove_all(comboVisual);
	pixbuf = gdk_pixbuf_new_from_file("escritorio/alpha.png", NULL);
	imgscaled = gdk_pixbuf_scale_simple(pixbuf, 580, 340, GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(img, imgscaled);

	for (int i = 0; i < Len(dem); i++) gtk_combo_box_text_append(comboVisual, dem[i].name, dem[i].label);
}

void on_WMRadioBtn_toggled () {
	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual"), TRUE); 
	gtk_combo_box_text_remove_all(comboVisual);
	pixbuf = gdk_pixbuf_new_from_file("escritorio/alpha.png", NULL);
	imgscaled = gdk_pixbuf_scale_simple(pixbuf, 580, 340, GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(img, imgscaled);

	for (int i = 0; i < Len(wmm); i++) gtk_combo_box_text_append(comboVisual, wmm[i].name, wmm[i].label); 
}


void on_TTYRadioBtn_toggled () {

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual"), FALSE); 
	pixbuf = gdk_pixbuf_new_from_file("escritorio/tty.png", NULL);
	imgscaled = gdk_pixbuf_scale_simple(pixbuf, 580, 340, GDK_INTERP_BILINEAR);
	gtk_image_set_from_pixbuf(img, imgscaled);
}

void on_comboVisual_changed(GtkComboBox *comboVisual, gpointer data)  {
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
    g_print("Elección Id: %s |  Nombre: %s \n", active_id, active_text);
    pixbuf = gdk_pixbuf_new_from_file(active_id, NULL);
    imgscaled = gdk_pixbuf_scale_simple(pixbuf, 580, 340, GDK_INTERP_BILINEAR);
    gtk_image_set_from_pixbuf(img, imgscaled);

	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '33c desktop=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}
