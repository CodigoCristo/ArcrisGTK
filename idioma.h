void on_btnidioma_clicked () {

  char* idiomatex;

  g_spawn_command_line_sync ("sh bash/variables.sh language", &idiomatex, NULL, NULL, NULL);
  gtk_label_set_label (idioma, idiomatex);
  printf("Idioma: %s \n", idiomatex);

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '5c locacion=%c%s UTF-8%c' bash/variables.sh", 34,idiomatex,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}

void on_btnteclado_clicked () {

  char* tecladotex;

  g_spawn_command_line_sync ("sh bash/variables.sh teclado", &tecladotex, NULL, NULL, NULL);
  gtk_label_set_label (ubicatecla, tecladotex);
  printf("Teclado: %s \n", tecladotex);

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '6c teclado=%c%s%c' bash/variables.sh", 34,tecladotex,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("setxkbmap -layout %s", tecladotex);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  

}


void on_btnzonahoraria_clicked () {

  char* zonahorariatex;

  g_spawn_command_line_sync ("sh bash/variables.sh timezone", &zonahorariatex, NULL, NULL, NULL);
  gtk_label_set_label (zonahoraria, zonahorariatex);
  printf("Zona Horaria: %s \n", zonahorariatex);

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '4c zonahoraria=%c%s%c' bash/variables.sh", 34,zonahorariatex,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}




/*/////////////////////////////////////////////////////////////////////////////////
// 1 . BOTON DE ACTUALIZAR DATOS
/////////////////////////////////////////////////////////////////////////////////
void on_locale_clicked(GtkButton *locale, gpointer data) {


    char* zonahorariatex;
    char* ubicatex;
    char* idiomatex;

g_spawn_command_line_sync ("sh bash/script.sh idioma", &idiomatex, NULL, NULL, NULL);
gtk_label_set_label (idioma, idiomatex);

g_spawn_command_line_sync ("sh bash/script.sh ubica", &ubicatex, NULL, NULL, NULL);
gtk_label_set_label (ubicatecla, ubicatex);


g_spawn_command_line_sync ("sh bash/script.sh zonahoraria", &zonahorariatex, NULL, NULL, NULL);
gtk_label_set_label (zonahoraria, zonahorariatex);


printf("Ubicación: %s \n", ubicatex);
printf("Idioma: %s \n", idiomatex);
printf("Zona Horaria: %s \n", zonahorariatex);

   
//USO DEL COMANDO   SED
gchar *commandline, **command;

commandline = g_strdup_printf("sed -i '2c idioma=%c%s%c' bash/variables.sh", 34,idiomatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("sed -i '3c ubicacion=%c%s%c' bash/variables.sh", 34,ubicatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("sed -i '4c zonahoraria=%c%s%c' bash/variables.sh", 34,zonahorariatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);
g_strfreev(command);
}
/////////////////////////////////////////////////////////////////////////////////







/////////////////////////////////////////////////////////////////////////////////
// 2 . COMBOBOX IDIOMA Y TECLADO
/////////////////////////////////////////////////////////////////////////////////

void menuidioma () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "idioma_sistema");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista = 0;
  g_spawn_command_line_sync("sudo sh bash/script.sh idioma-sistema", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista = i;
    g_strfreev(lines);
  }
  g_free(output);

  if (lista = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}



void menutecladosistema () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "teclado_sistema");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista = 0;
  g_spawn_command_line_sync("sudo sh bash/script.sh teclado-sistema", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista = i;
    g_strfreev(lines);
  }
  g_free(output);

  if (lista = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}



/////////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////////
// 3 . SEÑALES DE COMBOBOX IDIOMA
/////////////////////////////////////////////////////////////////////////////////

void on_idioma_sistema_changed(GtkWidget* widget, gpointer data) {
  
  gchar *idioma_select;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "idioma_sistema");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &idioma_select, -1);
  if (strlen(idioma_select) == 0) {
    g_free(idioma_select);
    idioma_select = g_strdup(NULL);         
  }

  printf("Idioma del Sistema: %s \n", idioma_select);

//USO DEL COMANDO   SED
commandline = g_strdup_printf("sed -i '5c locale=%c%s%c' bash/variables.sh", 34,idioma_select,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}



void on_teclado_sistema_changed(GtkWidget* widget, gpointer data) {
  
  gchar *idioma_select;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "teclado_sistema");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &idioma_select, -1);
  if (strlen(idioma_select) == 0) {
    g_free(idioma_select);
    idioma_select = g_strdup(NULL);         
  }

  printf("Teclado del Sistema: %s \n", idioma_select);

//USO DEL COMANDO   SED
commandline = g_strdup_printf("sed -i '6c keyboardX=%c%s%c' bash/variables.sh", 34,idioma_select,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("setxkbmap -layout %s", idioma_select);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}

*/











/*//////////////////////////////  INT MAIN
//Locación lista
char* zonahorariatex;
char* ubicatex;
char* idiomatex;

g_spawn_command_line_sync ("sh bash/script.sh idioma", &idiomatex, NULL, NULL, NULL);
gtk_label_set_label (idioma, idiomatex);

g_spawn_command_line_sync ("sh bash/script.sh ubica", &ubicatex, NULL, NULL, NULL);
gtk_label_set_label (ubica, ubicatex);

g_spawn_command_line_sync ("sh bash/script.sh zonahoraria", &zonahorariatex, NULL, NULL, NULL);
gtk_label_set_label (zonahoraria, zonahorariatex);

system("clear");

printf("Ubicación: %s \n", ubicatex);
printf("Idioma: %s \n", idiomatex);
printf("Zona Horaria: %s \n", zonahorariatex);


//USO DEL COMANDO   SED
gchar *commandline, **command;

commandline = g_strdup_printf("sed -i '2c idioma=%c%s%c' bash/variables.sh", 34,idiomatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("sed -i '3c ubicacion=%c%s%c' bash/variables.sh", 34,ubicatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);

commandline = g_strdup_printf("sed -i '4c zonahoraria=%c%s%c' bash/variables.sh", 34,zonahorariatex,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);
g_strfreev(command);
*////////////////////////////////////////////////


