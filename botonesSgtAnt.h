/* --------------------------------------------
// Inicio de botones de siguiente y anterior //
-----------------------------------------------*/



void on_btnAnt1_clicked (GtkButton *btn, gpointer data)
{
	g_application_quit((GApplication*) app);
}

void on_btnSig1_clicked (GtkButton *btn, gpointer data)
{
gtk_stack_set_visible_child_full (stack, "Idioma", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle1,FALSE);
gtk_toggle_button_set_active (toggle2,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

//---
void on_btnSig2_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Disco", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle2,FALSE);
gtk_toggle_button_set_active (toggle3,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

void on_btnAnt2_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Bienvenida", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle2,FALSE);
gtk_toggle_button_set_active (toggle1,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 


}

//---
void on_btnSig3_clicked (GtkButton *btn, gpointer data) {

if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiodiscoauto) ) ) {


  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '10c diskauto=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '11c diskautoencryp=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '12c diskmanual=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

char* nombrediscoauto;
g_spawn_command_line_sync ("sudo sh bash/variables.sh namediskauto", &nombrediscoauto, NULL, NULL, NULL);
gtk_label_set_label (disklabelauto, nombrediscoauto);

gtk_stack_set_visible_child_full (stack, "DiscoAuto", GTK_STACK_TRANSITION_TYPE_NONE);

/*gtk_toggle_button_set_active (toggle3,FALSE);
gtk_toggle_button_set_active (toggle4,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE);
*/

}

else if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiodiscolvm) ) ) {

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '10c diskauto=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '11c diskautoencryp=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '12c diskmanual=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  char *encrypass;
  g_object_get(entryencrypt, "text", &encrypass, NULL);
  g_print("Clave de Disco: %s\n", encrypass);

  commandline = g_strdup_printf("sed -i '21c keyencryp=%c%s%c' bash/variables.sh", 34,encrypass,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


gtk_stack_set_visible_child_full (stack, "Usuario", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle3,FALSE);
gtk_toggle_button_set_active (toggle4,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE);



}

else if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radiodiscomanual) ) ) {

  gchar *commandline, **command;

  commandline = g_strdup_printf("sed -i '10c diskauto=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '11c diskautoencryp=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '12c diskmanual=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  gtk_stack_set_visible_child_full (stack, "Particiones", GTK_STACK_TRANSITION_TYPE_SLIDE_LEFT);

listaboot();
listaparticionroot();
listaparticionswap();
listaparticionhome();

}

}



void on_btnAnt3_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Idioma", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle3,FALSE);
gtk_toggle_button_set_active (toggle2,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

gtk_widget_grab_focus ((GtkWidget *) gtk_builder_get_object(builder, "window"));

}


//---
void on_btnSig4_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Usuario", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle4,TRUE);
gtk_toggle_button_set_active (toggle3,FALSE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

void on_btnAnt4_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Disco", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle4,FALSE);
gtk_toggle_button_set_active (toggle3,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}



//---
void on_btnSig5_clicked (GtkButton *btn, gpointer data)
{

  gchar *commandline, **command;

  char *texuser;
  char *texpasswduser;
  char *texhostname;
  char *texpasswdroot;

  g_object_get(entryuser, "text", &texuser, NULL);
  g_print("Usuario: %s\n", texuser);

  g_object_get(entrypassconfirmuser, "text", &texpasswduser, NULL);
  g_print("Contraseña Usuario: %s\n", texpasswduser);

  g_object_get(entryhostname, "text", &texhostname, NULL);
  g_print("Hostname: %s\n", texhostname);

  g_object_get(entrypassroot, "text", &texpasswdroot, NULL);
  g_print("Contraseña Root: %s\n", texpasswdroot);

  commandline = g_strdup_printf("sed -i '25c user=%c%s%c' bash/variables.sh", 34,texuser,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '26c passwduser=%c%s%c' bash/variables.sh", 34,texpasswduser,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


  commandline = g_strdup_printf("sed -i '27c hostname=%c%s%c' bash/variables.sh", 34,texhostname,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


  commandline = g_strdup_printf("sed -i '28c passwdroot=%c%s%c' bash/variables.sh", 34,texpasswdroot,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);


gtk_stack_set_visible_child_full (stack, "Escritorios", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle4,FALSE);
gtk_toggle_button_set_active (toggle5,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

void on_btnAnt5_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Disco", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle4,FALSE);
gtk_toggle_button_set_active (toggle3,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

//---
void on_btnSig6_clicked (GtkButton *btn, gpointer data)
{

gchar *commandline, **command;

if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(TTYRadioBtn) ) ) {

  commandline = g_strdup_printf("sed -i '30c ttyselec=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '31c desktopDE=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '32c desktopDW=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}

else if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(DERadioBtn) ) ) {

  commandline = g_strdup_printf("sed -i '30c ttyselec=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '31c desktopDE=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '32c desktopDW=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}


else if ( gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(WMRadioBtn) ) ) {

  commandline = g_strdup_printf("sed -i '30c ttyselec=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '31c desktopDE=%cFALSE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

  commandline = g_strdup_printf("sed -i '32c desktopDW=%cTRUE%c' bash/variables.sh", 34,34);
  g_shell_parse_argv(commandline, NULL, &command, NULL);
  g_free(commandline);
  g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH, NULL, NULL, NULL, NULL);

}

gtk_stack_set_visible_child_full (stack, "Programas", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle5,FALSE);
gtk_toggle_button_set_active (toggle6,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 
}

void on_btnAnt6_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Usuario", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle5,FALSE);
gtk_toggle_button_set_active (toggle4,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

//---
void on_btnSig7_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Extras", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle6,FALSE);
gtk_toggle_button_set_active (toggle7,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

void on_btnAnt7_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Escritorios", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle6,FALSE);
gtk_toggle_button_set_active (toggle5,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), TRUE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

//---
void on_btnSig8_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Instalacion", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle7,FALSE);
gtk_toggle_button_set_active (toggle8,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

char *comando;
comando = "sh final\n";
vte_terminal_feed_child (term, comando, -1);

}

void on_btnAnt8_clicked (GtkButton *btn, gpointer data)
{
 	gtk_stack_set_visible_child_full (stack, "Programas", GTK_STACK_TRANSITION_TYPE_NONE);
gtk_toggle_button_set_active (toggle7,FALSE);
gtk_toggle_button_set_active (toggle6,TRUE);
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle1"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle2"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle3"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle4"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle5"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle6"), TRUE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle7"), FALSE);  
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle8"), FALSE); 
gtk_widget_set_sensitive ((GtkWidget *) gtk_builder_get_object(builder, "toggle9"), FALSE); 

}

/* --------------------------------------------
// Final de botones de siguiente y anterior  //
-----------------------------------------------*/