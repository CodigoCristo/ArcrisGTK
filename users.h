

gboolean user_input(GtkWidget *self, GdkEvent *ev, gpointer data) {
  const char *val = gtk_entry_get_text(GTK_ENTRY(self));

  if ( g_regex_match(patt, val, 0, NULL) ) {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-completed-symbolic"
    );
  } else {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-error-symbolic"
    );
  }

  return FALSE;
}

gboolean hostname_input(GtkWidget *self, GdkEvent *ev, gpointer data) {
  const char *val = gtk_entry_get_text(GTK_ENTRY(self));

  if ( g_regex_match(patthost, val, 0, NULL) ) {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-completed-symbolic"
    );
  } else {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-error-symbolic"
    );
  }

  return FALSE;
}

gboolean pass_input(GtkWidget *self, GdkEvent *ev, gpointer data) {
  const char *val = gtk_entry_get_text(GTK_ENTRY(self));

  if ( g_regex_match(pattkey, val, 0, NULL) ) {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-completed-symbolic"
    );
  } else {
    gtk_entry_set_icon_from_icon_name(
      GTK_ENTRY(self),
      GTK_ENTRY_ICON_SECONDARY, "process-error-symbolic"
    );
  }

  return FALSE;
}

gboolean confirm_input(GtkWidget* self, GdkEvent* ev, gpointer data) {
  char *original, *confirmation;
  g_object_get(entrypassuser, "text", &original, NULL);
  g_object_get(entrypassconfirmuser, "text", &confirmation, NULL);
    const char *val = gtk_entry_get_text(GTK_ENTRY(self));

  if ( g_str_equal(confirmation, original) && g_regex_match(pattkey, val, 0, NULL) ) {
    g_object_set(entrypassconfirmuser, "secondary-icon-name", "process-completed-symbolic", NULL);
  } else {

    g_object_set(entrypassconfirmuser, "secondary-icon-name", "process-error-symbolic", NULL);
  }
}



void users () {
  
  // https://regexlib.com/Search.aspx?k=password
  patt = g_regex_new("^([a-z]{4,15})$", 0, 0, NULL);
  patthost = g_regex_new("^([a-z]+[a-z0-9]*)$", 0, 0, NULL);
  pattkey=g_regex_new("^.{6,10}$", 0, 0, NULL);

  g_signal_connect(entryuser,    		 	"notify::text", G_CALLBACK(user_input),    NULL);
  g_signal_connect(entrypassuser,    		"notify::text", G_CALLBACK(pass_input),    NULL);
  g_signal_connect(entrypassconfirmuser, 	"notify::text", G_CALLBACK(confirm_input), NULL);
  g_signal_connect(entryhostname, 			"notify::text", G_CALLBACK(hostname_input), NULL);
  g_signal_connect(entrypassroot, 			"notify::text", G_CALLBACK(pass_input), NULL);


}


//^([1-zA-Z0-1@]{1,255})$


void on_checkmostrarclaves_toggled (GtkWidget *self, gpointer data) {
  gboolean active = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(self));

  if (active) {
    gtk_entry_set_visibility(GTK_ENTRY(entrypassuser),    		TRUE);
	gtk_entry_set_visibility(GTK_ENTRY(entrypassconfirmuser),   TRUE);
	gtk_entry_set_visibility(GTK_ENTRY(entrypassroot),    		TRUE);

  } else {
    gtk_entry_set_visibility(GTK_ENTRY(entrypassuser),    		FALSE);
	gtk_entry_set_visibility(GTK_ENTRY(entrypassconfirmuser),   FALSE);
	gtk_entry_set_visibility(GTK_ENTRY(entrypassroot),    		FALSE);

  }
}