GtkApplication  *app;
GtkBuilder      *builder;
GtkWindow       *window;
GtkStack		*stack;
GtkBox			*arc;
GtkSeparator	*separator;
GtkToggleButton	 *toggle1;
GtkToggleButton	 *toggle2;
GtkToggleButton	 *toggle3;
GtkToggleButton	 *toggle4;
GtkToggleButton	 *toggle5;
GtkToggleButton	 *toggle6;
GtkToggleButton	 *toggle7;
GtkToggleButton	 *toggle8;
GtkToggleButton	 *toggle9;

GtkButton 		 *btntelegram;
GtkButton 		 *btnyoutube;

GtkLabel 		 *ubicatecla;
GtkLabel 		 *idioma;
GtkLabel 		 *zonahoraria;
GtkButton 		 *btnidioma;
GtkButton 		 *btnteclado;
GtkButton 		 *btnzonahoraria;

GtkTreeIter      iter;
GtkComboBox      *listwidget;
GtkListStore     *list;
GtkTreeModelFilter     *model;


GtkListStore 	 *lists_idioma;

GtkListStore 	 *lists_sistema;


GtkComboBox 	 *seleccion_disco;
GtkListStore 	 *lists_discoselect;
GtkLabel 		 *arranque;
GtkLabel 		 *disklabel;

GtkRadioButton	 *radiodiscoauto;
GtkRadioButton	 *radiodiscolvm;
GtkRadioButton	 *radiodiscomanual;


GtkBox 			 *diskelecc1;
GtkBox 			 *diskelecc2;
GtkBox 			 *diskelecc3;

GtkLabel 		 *texdiskboot;
GtkLabel 		 *infodiskmanual;
GtkLabel 		 *disklabelauto;
GtkLabel 		 *diskmanual;

GtkComboBox 	 *partiboot;
GtkListStore 	 *listboot;
GtkLabel 		 *diskboot;

GtkComboBox 	 *partiroot;
GtkListStore 	 *listroot;
GtkLabel 		 *diskroot;

GtkComboBox 	 *partiswap;
GtkListStore 	 *listswap;
GtkLabel 		 *diskswap;

GtkComboBox 	 *partihome;
GtkListStore 	 *listhome;
GtkLabel 		 *diskhome;

GtkButtonBox 	 *boxgparted;
GtkButton	 	 *gparted;
GtkButton	 	 *tablapartitionnew;
GtkLabel 		 *textmanual;
GtkButton	 	 *actualizarlista;

GtkLabel		 *keyencrypt;
GtkEntry		 *entryencrypt;
GtkCheckButton	 *checkencrypt;

GtkEntry		 *entryuser;
GtkEntry		 *entrypassuser;
GtkEntry		 *entrypassconfirmuser;
GtkEntry		 *entryhostname;
GtkEntry		 *entrypassroot;
GtkCheckButton 	 *checkmostrarclaves;
GRegex* 		 patt;
GRegex* 		 patthost;
GRegex* 		 pattkey;

GtkImage 	 	 *img;
GdkPixbuf        *pixbuf, *imgscaled;
GtkRadioButton 	 *TTYRadioBtn;
GtkRadioButton 	 *WMRadioBtn;
GtkRadioButton 	 *DERadioBtn;
GtkComboBoxText  *comboVisual;

GtkLabel 		 *modulo1;
GtkLabel 		 *modulo2;
GtkLabel 		 *modulo3;
GtkComboBoxText  *comboVisual1;
GtkComboBoxText  *comboVisual2;
GtkComboBoxText  *comboVisual3;
GtkComboBoxText  *comboVisual4;
GtkComboBoxText  *comboVisual5;
GtkComboBoxText  *comboVisual6;
GtkComboBoxText  *comboVisual7;
GtkComboBoxText  *comboVisual8;
GtkButton	 	 *programbase;


GtkViewport		 *termView;
VteTerminal      *term;
VtePty           *pty;
GtkButton	 	 *install;
GtkButton	 	 *details;
GtkButton	 	 *finalize;


void elementos () {

builder       	= (GtkBuilder*)    	gtk_builder_new_from_file("instalarch2.glade");
window         	= (GtkWindow*)     	gtk_builder_get_object(builder, "window");
stack          	= (GtkStack*)      	gtk_builder_get_object(builder, "stack");
arc          	= (GtkBox*)      	gtk_builder_get_object(builder, "arc");
separator       = (GtkSeparator*)   gtk_builder_get_object(builder, "separator");


toggle1          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle1");
toggle2          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle2");
toggle3          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle3");
toggle4          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle4");
toggle5          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle5");
toggle6          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle6");
toggle7          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle7");
toggle8          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle8");
toggle9          	= (GtkToggleButton*)     gtk_builder_get_object(builder, "toggle9");


btntelegram         = (GtkButton*)     		gtk_builder_get_object(builder, "btntelegram");
btnyoutube          = (GtkButton*)     		gtk_builder_get_object(builder, "btnyoutube");


ubicatecla          = (GtkLabel*)     		gtk_builder_get_object(builder, "ubicatecla");
idioma          	= (GtkLabel*)     		gtk_builder_get_object(builder, "idioma");
zonahoraria         = (GtkLabel*)     		gtk_builder_get_object(builder, "zonahoraria");
btnidioma          	= (GtkButton*)     		gtk_builder_get_object(builder, "btnidioma");
btnteclado          = (GtkButton*)     		gtk_builder_get_object(builder, "btnteclado");
btnzonahoraria      = (GtkButton*)     		gtk_builder_get_object(builder, "btnzonahoraria");


list            	= (GtkListStore*)  		gtk_builder_get_object(builder, "list");
model           	= (GtkTreeModelFilter*) gtk_builder_get_object(builder, "model");

list            	= (GtkListStore*)  		gtk_builder_get_object(builder, "list");
listwidget          = (GtkComboBox*)  		gtk_builder_get_object(builder, "listwidget");



lists_idioma      	= (GtkListStore*)     	gtk_builder_get_object(builder, "lists_idioma");

lists_sistema      	= (GtkListStore*)     	gtk_builder_get_object(builder, "lists_sistema");


seleccion_disco     = (GtkComboBox*)     	gtk_builder_get_object(builder, "seleccion_disco");
lists_discoselect   = (GtkListStore*)     	gtk_builder_get_object(builder, "lists_discoselect");
arranque   			= (GtkLabel*)     		gtk_builder_get_object(builder, "arranque");
disklabel   		= (GtkLabel*)     		gtk_builder_get_object(builder, "disklabel");

radiodiscoauto      = (GtkRadioButton*)     gtk_builder_get_object(builder, "radiodiscoauto");
radiodiscolvm   	= (GtkRadioButton*)     gtk_builder_get_object(builder, "radiodiscolvm");
radiodiscomanual   	= (GtkRadioButton*)    	gtk_builder_get_object(builder, "radiodiscomanual");

diskelecc1   		= (GtkBox*)    			gtk_builder_get_object(builder, "diskelecc1");
diskelecc2   		= (GtkBox*)    			gtk_builder_get_object(builder, "diskelecc2");
diskelecc3   		= (GtkBox*)    			gtk_builder_get_object(builder, "diskelecc3");

keyencrypt   		= (GtkLabel*)    		gtk_builder_get_object(builder, "keyencrypt");
entryencrypt   		= (GtkEntry*)    		gtk_builder_get_object(builder, "entryencrypt");
checkencrypt   		= (GtkCheckButton*)    	gtk_builder_get_object(builder, "checkencrypt");


boxgparted   		= (GtkButtonBox*)     	gtk_builder_get_object(builder, "boxgparted");
gparted   			= (GtkButton*)     		gtk_builder_get_object(builder, "gparted");
tablapartitionnew   = (GtkButton*)     		gtk_builder_get_object(builder, "tablapartitionnew");
textmanual   		= (GtkLabel*)     		gtk_builder_get_object(builder, "textmanual");


texdiskboot   		= (GtkLabel*)     		gtk_builder_get_object(builder, "texdiskboot");
diskmanual   		= (GtkLabel*)     		gtk_builder_get_object(builder, "diskmanual");
infodiskmanual   	= (GtkLabel*)     		gtk_builder_get_object(builder, "infodiskmanual");
disklabelauto   	= (GtkLabel*)     		gtk_builder_get_object(builder, "disklabelauto");


partiboot   		= (GtkComboBox*)     	gtk_builder_get_object(builder, "partiboot");
listboot   			= (GtkListStore*)     	gtk_builder_get_object(builder, "listboot");
diskboot   			= (GtkLabel*)     		gtk_builder_get_object(builder, "diskboot");

partiroot   		= (GtkComboBox*)     	gtk_builder_get_object(builder, "partiroot");
listroot   			= (GtkListStore*)     	gtk_builder_get_object(builder, "listroot");
diskroot   			= (GtkLabel*)     		gtk_builder_get_object(builder, "diskroot");

partiswap   		= (GtkComboBox*)     	gtk_builder_get_object(builder, "partiswap");
listswap   			= (GtkListStore*)     	gtk_builder_get_object(builder, "listswap");
diskswap   			= (GtkLabel*)     		gtk_builder_get_object(builder, "diskswap");

partihome   		= (GtkComboBox*)     	gtk_builder_get_object(builder, "partihome");
listhome   			= (GtkListStore*)     	gtk_builder_get_object(builder, "listhome");
diskhome   			= (GtkLabel*)     		gtk_builder_get_object(builder, "diskhome");

entryuser   		= (GtkEntry*)     		gtk_builder_get_object(builder, "entryuser");
entrypassuser   	= (GtkEntry*)     		gtk_builder_get_object(builder, "entrypassuser");
entrypassconfirmuser = (GtkEntry*)     		gtk_builder_get_object(builder, "entrypassconfirmuser");
entryhostname   	= (GtkEntry*)     		gtk_builder_get_object(builder, "entryhostname");
entrypassroot   	= (GtkEntry*)     		gtk_builder_get_object(builder, "entrypassroot");
checkmostrarclaves  = (GtkCheckButton*)     gtk_builder_get_object(builder, "checkmostrarclaves");


img  				= (GtkImage*)     		gtk_builder_get_object(builder, "img");
TTYRadioBtn  		= (GtkRadioButton*)     gtk_builder_get_object(builder, "TTYRadioBtn");
WMRadioBtn  		= (GtkRadioButton*)     gtk_builder_get_object(builder, "WMRadioBtn");
DERadioBtn  		= (GtkRadioButton*)     gtk_builder_get_object(builder, "DERadioBtn");
comboVisual  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual");


modulo1   			= (GtkLabel*)     		gtk_builder_get_object(builder, "modulo1");
modulo2   			= (GtkLabel*)     		gtk_builder_get_object(builder, "modulo2");
modulo3   			= (GtkLabel*)     		gtk_builder_get_object(builder, "modulo3");


comboVisual1  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual1");
comboVisual2  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual2");
comboVisual3  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual3");
comboVisual4  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual4");
comboVisual5  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual5");
comboVisual6  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual6");
comboVisual7  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual7");
comboVisual8  		= (GtkComboBoxText*)    gtk_builder_get_object(builder, "comboVisual8");
programbase  		= (GtkButton*)    		gtk_builder_get_object(builder, "programbase");


termView        	= (GtkViewport*)   gtk_builder_get_object(builder, "termView");
term           		= (VteTerminal*)   vte_terminal_new(); 
install  			= (GtkButton*)    gtk_builder_get_object(builder, "install");
details  			= (GtkButton*)    gtk_builder_get_object(builder, "details");
finalize  			= (GtkButton*)    gtk_builder_get_object(builder, "finalize");



}



void on_btnyoutube_clicked () {

gchar *commandline, **command;
commandline = g_strdup_printf("xdg-open https://www.youtube.com/c/CódigoCristo");
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);
g_strfreev(command);

}


void on_btntelegram_clicked () {

gchar *commandline, **command;
commandline = g_strdup_printf("xdg-open https://t.me/ArchLinuxCristo");
g_shell_parse_argv(commandline, NULL, &command, NULL);
g_free(commandline);
g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);
g_strfreev(command);

}