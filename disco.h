
/////////////////////////////////////////////////////////////////////////////////
// DISCO
/////////////////////////////////////////////////////////////////////////////////

void actualizarnombreMBRorGPT () {

char* arranquesistema;
g_spawn_command_line_sync ("sudo sh bash/script.sh tablapartition", &arranquesistema, NULL, NULL, NULL);
gtk_label_set_label (disklabel, arranquesistema);

}

void on_tablapartitionnew_clicked () {

/*gchar *commandline, **command;
commandline = g_strdup_printf("sudo sh bash/script.sh creartablapartition");
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);
g_strfreev(command);*/

char* arranquesistema;
g_spawn_command_line_sync ("sudo sh bash/script.sh creartablapartition", &arranquesistema, NULL, NULL, NULL);
gtk_label_set_label (disklabel, arranquesistema);

}


void discoseleccion () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "seleccion_disco");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista_disco = 0;
  g_spawn_command_line_sync("sudo sh bash/script.sh disk", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista_disco = i;
    g_strfreev(lines);
  }
  g_free(output);

  if (lista_disco = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}


void on_seleccion_disco_changed(GtkWidget* widget, gpointer data) {
  
  gchar *disk_select;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "seleccion_disco");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &disk_select, -1);
  if (strlen(disk_select) == 0) {
    g_free(disk_select);
    disk_select = g_strdup(NULL);         
  }


  printf("Disco Seleccionado: %s \n", disk_select);

//USO DEL COMANDO   SED
commandline = g_strdup_printf("sed -i '8c diskselect=%c%s%c' bash/variables.sh", 34,disk_select,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("sed -i '2c diskselect=%c%s%c' bash/script.sh", 34,disk_select,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

char* arranquesistema;
g_spawn_command_line_sync ("sudo sh bash/script.sh tablapartition", &arranquesistema, NULL, NULL, NULL);
gtk_label_set_label (disklabel, arranquesistema);


char* nombredisco;
g_spawn_command_line_sync ("sudo sh bash/variables.sh namedisk", &nombredisco, NULL, NULL, NULL);
gtk_label_set_label (diskmanual, nombredisco);


char* infodisco;
g_spawn_command_line_sync ("sudo sh bash/variables.sh infodisk", &infodisco, NULL, NULL, NULL);
gtk_label_set_label (infodiskmanual, infodisco);

}



/////////////////////////////////////////////////////////////////////////////////

void on_radiodiscoauto_toggled(GtkWidget *self, gpointer data) {

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc1"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc2"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc3"), FALSE);

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "keyencrypt"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "entryencrypt"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "checkencrypt"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "boxgparted"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "textmanual"), FALSE);  

}

void on_radiodiscolvm_toggled (GtkWidget *self, gpointer data) {

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc1"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc2"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc3"), FALSE); 

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "keyencrypt"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "entryencrypt"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "checkencrypt"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "boxgparted"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "textmanual"), FALSE);  



}



void on_checkencrypt_toggled (GtkWidget *self, gpointer data) {
  gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(self));

  if (active) {
    gtk_entry_set_visibility(GTK_ENTRY(entryencrypt),    TRUE);

  } else {
    gtk_entry_set_visibility(GTK_ENTRY(entryencrypt),    FALSE);

  }
}


void on_radiodiscomanual_toggled (GtkWidget *self, gpointer data) {

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc1"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc2"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "diskelecc3"), TRUE); 

gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "boxgparted"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "textmanual"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "keyencrypt"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "entryencrypt"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "checkencrypt"), FALSE);  


}






/*
void on_radiodiscoauto_toggled () {

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '10c diskauto=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  gtk_stack_set_visible_child_full (stack, "Disco", GTK_STACK_TRANSITION_TYPE_NONE);
  
}



void on_radiodiscomanual_toggled () {

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '10c diskauto=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  gtk_stack_set_visible_child_full (stack, "Particiones", GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);

}

*/



