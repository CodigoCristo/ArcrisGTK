
void infomodulos () {


char* modulowifi;
g_spawn_command_line_sync ("sudo sh bash/script.sh wifi", &modulowifi, NULL, NULL, NULL);
gtk_label_set_label (modulo1, modulowifi);

char* modulobluthu;
g_spawn_command_line_sync ("sudo sh bash/script.sh blutu", &modulobluthu, NULL, NULL, NULL);
gtk_label_set_label (modulo2, modulobluthu);

char* modulovideo;
g_spawn_command_line_sync ("sudo sh bash/script.sh tarjetavideo", &modulovideo, NULL, NULL, NULL);
gtk_label_set_label (modulo3, modulovideo);


typedef struct { const gchar *nameprogram, *labelprogram; } CStore;
CStore kernel[] = {
  { "linux", "Linux Stable" },
  { "linux-hardened", "Linux Hardened" },
  { "linux-lts", "Linux LTS" },
  { "linux-zen", "Linux Zen" },
};

CStore video[] = {
  { "auto", "Automático" },
  { "videovesa", "Video vesa (Generic All)" },
  { "videointel", "Intel (Open Source)" },
  { "videoati", "AMD - ATI (Open Source)" },
  { "videoradeon", "AMD - Radeon (Open Source)" },
  { "videonouveau", "Nvidia (Open Source)" },
  { "linux-zen", "Nvidia 440xx (Linux Stable)" },
  { "linux-zen", "Nvidia 390xx (Linux Stable)" },
  { "linux-zen", "Nvidia 440xx (Linux LTS)" },
  { "linux-zen", "Nvidia 390xx (Linux LTS)" },
  { "linux-zen", "Nvidia 440xx (Linux Hardened - Zen)" },
  { "linux-zen", "Nvidia 390xx (Linux Hardened - Zen)" },
  { "linux-zen", "Nvidia 440xx (Linux Stable + Intel)" },
};

CStore shell[] = {
  { "auto", "bash" },
  { "zsh", "zsh" },
  { "fish", "fish" },
  { "ksh", "ksh" },
};

CStore audio[] = {
  { "auto", "Alsa Audio" },
  { "audiopulse", "Pulse Audio" },
  { "audiojack", "Jack Audio" },
  { "audiopipewire", "Pipewire Audio" },
};


CStore aur[] = {
  { "none", "No deseo" },
  { "yay", "yay (Terminal)" },
  { "paru", "paru (Terminal)" },
  { "pamac", "Pamac (Graphical)" },
  { "octopi", "Octopi (Graphical)" },
};

CStore blutu[] = {
  { "none", "No disponible" },
  { "bluez", "Bluetoothctl (Terminal)" },
  { "blueman", "Blueman (Graphical)" },
};


CStore sandbox[] = {
  { "none", "No deseo" },
  { "snap", "Snap" },
  { "flatpak", "Flatpak" },
};


CStore wifi[] = {
  { "none", "No disponible" },
  { "auto", "Automatico" },
  { "broadcom-wl", "Broadcom 802.11 Linux Stable" },
  { "broadcom-wl-dkms", "Broadcom 802.11 Others Kernels" },
};


	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual1"), TRUE); 
	for (int i = 0; i < Len(kernel); i++) gtk_combo_box_text_append(comboVisual1, kernel[i].nameprogram, kernel[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual2"), TRUE); 
	for (int i = 0; i < Len(video); i++) gtk_combo_box_text_append(comboVisual2, video[i].nameprogram, video[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual3"), TRUE); 
	for (int i = 0; i < Len(shell); i++) gtk_combo_box_text_append(comboVisual3, shell[i].nameprogram, shell[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual4"), TRUE); 
	for (int i = 0; i < Len(audio); i++) gtk_combo_box_text_append(comboVisual4, audio[i].nameprogram, audio[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual5"), TRUE); 
	for (int i = 0; i < Len(aur); i++) gtk_combo_box_text_append(comboVisual5, aur[i].nameprogram, aur[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual6"), TRUE); 
	for (int i = 0; i < Len(blutu); i++) gtk_combo_box_text_append(comboVisual6, blutu[i].nameprogram, blutu[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual7"), TRUE); 
	for (int i = 0; i < Len(sandbox); i++) gtk_combo_box_text_append(comboVisual7, sandbox[i].nameprogram, sandbox[i].labelprogram);

	gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "comboVisual8"), TRUE); 
	for (int i = 0; i < Len(wifi); i++) gtk_combo_box_text_append(comboVisual8, wifi[i].nameprogram, wifi[i].labelprogram);

}





void on_comboVisual1_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '35c kernel=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}


void on_comboVisual2_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '36c video=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}



void on_comboVisual3_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '37c shell=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}



void on_comboVisual4_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '38c audio=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}


void on_comboVisual5_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '39c aur=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}



void on_comboVisual6_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '40c bluetooth=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}



void on_comboVisual7_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '41c sandbox=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}


void on_comboVisual8_changed(GtkComboBox *comboVisual, gpointer data)  {
 
  const gchar *active_id = gtk_combo_box_get_active_id(comboVisual);
  gchar *active_text = gtk_combo_box_text_get_active_text((GtkComboBoxText*) comboVisual);
  if (active_id != NULL) {
  g_print("Selecciono: %s | Nombre: %s\n", active_id, active_text);

 	gchar *commandline, **command;
	commandline = g_strdup_printf("sed -i '42c wifi=%c%s%c' bash/variables.sh", 34,active_id,34);
	g_shell_parse_argv(commandline, NULL, &command, NULL);
	g_free(commandline);
	g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  }
}



