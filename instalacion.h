// Con esta función, se abre la shell del usuario en la terminal de la pagina de la terminal
void spawnShell(VteTerminal *term, gint status, gpointer data)
{

  char **termArgv = (char *[]) { getenv("SHELL"), NULL };

  vte_terminal_spawn_async(
    term,            
    VTE_PTY_DEFAULT, 
    NULL,            
    termArgv,        
    NULL,            
    G_SPAWN_DEFAULT, 
    NULL,            
    NULL,            
    NULL,            
    -1,              
    NULL,           
    NULL,            
    NULL             
  );
}


void on_install_clicked () {

char *comando;
comando = "¬";
vte_terminal_feed_child (term, comando, -1);

}


void terminal () {

spawnShell(term, 0, NULL); // Hacemos que aparezca nuestra shell
gtk_container_add((GtkContainer*) termView, (GtkWidget*) term);

// Fuente de la terminal: Andale Mono, 12
PangoFontDescription *font;
font = pango_font_description_new();
pango_font_description_set_size(font, 10*PANGO_SCALE);
pango_font_description_set_family(font, "Hack");
vte_terminal_set_font(term, font);

}