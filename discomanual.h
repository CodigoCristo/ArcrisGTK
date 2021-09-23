
void listaboot () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiboot");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista_boot = 0;
  g_spawn_command_line_sync("sudo sh bash/variables.sh listaboot", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista_boot = i;
    g_strfreev(lines);
  }
  g_free(output);

  if (lista_boot = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);

  }

}




void listaparticionroot () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiroot");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista_root = 0;
  g_spawn_command_line_sync("sudo sh bash/variables.sh partiroot", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista_root = i;
    g_strfreev(lines);
  }
  g_free(output);


  if (lista_root = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}


void listaparticionswap () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiswap");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista_root = 0;
  g_spawn_command_line_sync("sudo sh bash/variables.sh partiswap", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista_root = i;
    g_strfreev(lines);
  }
  g_free(output);


  if (lista_root = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}




void listaparticionhome () {
  gchar **lines, *output;
  gint i;
  gint status;
/////////////////////////////////////////////////////////////////////////////////
  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partihome");
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  int lista_root = 0;
  g_spawn_command_line_sync("sudo sh bash/variables.sh partihome", &output, NULL, &status, NULL);
  if (status == 0) {
    lines = g_strsplit(output, "\n", 0);
    for (i=0; lines[i] != NULL && strlen(lines[i])>0; i++) {
      gtk_list_store_append(list, &iter);
      gtk_list_store_set(list, &iter, 0, lines[i], -1);
    }
    lista_root = i;
    g_strfreev(lines);
  }
  g_free(output);

  if (lista_root = 0){
   gtk_combo_box_set_active_iter(listwidget, &iter);
  }
}



void on_partiboot_changed(GtkWidget* widget, gpointer data) {
  
  gchar *disk_boot;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiboot");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &disk_boot, -1);
  if (strlen(disk_boot) == 0) {
    g_free(disk_boot);
    disk_boot = g_strdup(NULL);         
  }


  printf("Partición Boot: %s \n", disk_boot);


commandline = g_strdup_printf("sed -i '14c partiboot=%c%s%c' bash/variables.sh", 34,disk_boot,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


char* nombreboot;
g_spawn_command_line_sync ("sudo sh bash/variables.sh boot", &nombreboot, NULL, NULL, NULL);
gtk_label_set_label (diskboot, nombreboot);

}



void on_partiroot_changed(GtkWidget* widget, gpointer data) {
  
  gchar *disk_root;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiroot");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &disk_root, -1);
  if (strlen(disk_root) == 0) {
    g_free(disk_root);
    disk_root = g_strdup(NULL);         
  }


  printf("Partición Root: %s \n", disk_root);


commandline = g_strdup_printf("sed -i '15c partiroot=%c%s%c' bash/variables.sh", 34,disk_root,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


char* nombreroot;
g_spawn_command_line_sync ("sudo sh bash/variables.sh root", &nombreroot, NULL, NULL, NULL);
gtk_label_set_label (diskroot, nombreroot);

}



void on_partiswap_changed(GtkWidget* widget, gpointer data) {
  
  gchar *disk_swap;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partiswap");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &disk_swap, -1);
  if (strlen(disk_swap) == 0) {
    g_free(disk_swap);
    disk_swap = g_strdup(NULL);         
  }


  printf("Partición SWAP: %s \n", disk_swap);


commandline = g_strdup_printf("sed -i '18c partiswap=%c%s%c' bash/variables.sh", 34,disk_swap,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


char* nombreswap;
g_spawn_command_line_sync ("sudo sh bash/variables.sh swap", &nombreswap, NULL, NULL, NULL);
gtk_label_set_label (diskswap, nombreswap);

}




void on_partihome_changed(GtkWidget* widget, gpointer data) {
  
  gchar *disk_home;
  gchar *commandline, **command;

  listwidget = (GtkComboBox *) gtk_builder_get_object(builder, "partihome");
  gtk_combo_box_get_active_iter(listwidget, &iter);
  list = (GtkListStore *) gtk_combo_box_get_model(listwidget);
  gtk_tree_model_get((GtkTreeModel *) list, &iter, 0, &disk_home, -1);
  if (strlen(disk_home) == 0) {
    g_free(disk_home);
    disk_home = g_strdup(NULL);         
  }


  printf("Partición Home: %s \n", disk_home);


commandline = g_strdup_printf("sed -i '17c partihome=%c%s%c' bash/variables.sh", 34,disk_home,34);
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


gtk_label_set_label (diskhome, disk_home);

}




void on_gparted_clicked (GtkButton *gparted, gpointer data)
{
  char* nombredisco;
  g_spawn_command_line_sync ("sudo /bin/bash gparted", &nombredisco, NULL, NULL, NULL);

}



