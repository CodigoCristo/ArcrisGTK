#!/bin/sh
diskselect="/dev/sdc (7803MB)"

partition () {

disk=$(echo ${diskselect} | awk '{printf $1}')
diskgpt=$( fdisk -l ${disk} | grep -ic gpt )
diskmbr=$( fdisk -l ${disk} | grep -ic dos )
if [ $diskgpt == 1 ]
then
echo "GPT"
elif [ $diskmbr == 1 ]
then
echo "MBR"
else
echo "Sin definir"
fi

}

partitionnew (){

arranque=$( ls /sys/firmware/efi/ | grep -ic efivars )
if [ $arranque == 1 ]
then
( sudo sgdisk --zap-all ${disk} && sudo parted ${disk} mklabel gpt ) | zenity --progress --title="Creando Tabla de Particiones" --width=450 --pulsate --auto-close --no-cancel
else
( sudo sgdisk --zap-all ${disk} && (echo o ; echo w) | sudo fdisk ${disk} ) | zenity --progress --title="Creando Tabla de Particiones" --width=450 --pulsate --auto-close --no-cancel
fi

}

case "$1" in

"zonahoraria") 
printf $(curl https://ipapi.co/timezone)
;;

"ubica") 
printf $(curl https://ipapi.co/country_name)
;;

"idioma") 
printf $(curl https://ipapi.co/languages | awk -F "," '{print $1}')
;;

"idioma-sistema") 
cat text/locale.gen
;;

"teclado-sistema") 
cat text/localectlX11
;;

"teclado-terminal") 
cat text/localectlT
;;

"disk") 
echo "print devices" | parted | grep /dev/ | awk '{if (NR!=1) {print}}' | sed '/sr/d'
;;

"arranque") 
arranque=$( ls /sys/firmware/efi/ | grep -ic efivars )
if [ $arranque == 1 ]
then
echo "UEFI"
else
echo "BIOS LEGACY"
fi
;;


"tablapartition") 
disk=$(echo ${diskselect} | awk '{printf $1}')
diskgpt=$( fdisk -l ${disk} | grep -ic gpt )
diskmbr=$( fdisk -l ${disk} | grep -ic dos )
if [ $diskgpt == 1 ]
then
echo "GPT"
elif [ $diskmbr == 1 ]
then
echo "MBR"
else
echo "Sin definir"
fi
;;

"creartablapartition") 
disk=$(echo ${diskselect} | awk '{printf $1}')
zenity --question --title="Crear Tabla de Particiones" --width=500 --text="¿Está seguro que querer crear una nueva tabla de particiones? \n \
Crear una nueva tabla de perticiones borrará todos los datos existentes en el disco."

if [ $? = 0 ]; then

partitionnew
partition
else
exit

fi
;;


"arranquemanual") 
arranque=$( ls /sys/firmware/efi/ | grep -ic efivars )
if [ $arranque == 1 ]
then
echo "SISTEMA UEFI"
else
echo "SISTEMA BIOS LEGACY"
fi
;;


"diskmanual") 
fdisk -l | grep /dev/ | grep ":" | awk '{if (NR=1) {print  $2, $3, $4}}' | sed -e 's/.$//'
echo "Seleccionar..."
;;


"wifi") 
modulowifi=$( lspci | grep Network | grep -ic Network )
if [ $modulowifi == 1 ]
then
modulowifi=$( lspci | grep Network | awk -F " " '{print $5,$6,$7,$8,$9,$10,$11,$12,$13}' )
echo "<span font_desc='Open Sans Bold 10' foreground='#35358484e4e4'>${modulowifi}</span>"
else
echo '<span font_desc="Open Sans Bold 10" foreground="red">No disponible</span>'  
fi
;;

"blutu") 
modulobluthu=$( lsmod | grep bluetooth |  awk '{line = $0} END {print $0}' | grep -ic bluetooth )
if [ $modulobluthu == 1 ]
then
echo '<span font_desc="Open Sans Bold 10" foreground="#35358484e4e4">DISPONIBLE</span>'  
else
echo '<span font_desc="Open Sans Bold 10" foreground="red">No disponible</span>'  
fi
;;

"tarjetavideo") 
modulovideo=$( lspci | grep VGA |  awk '{line = $0} END {print $0}' | grep -ic VGA )
if [ $modulovideo == 1 ]
then
lspci | grep VGA |  awk -F " " '{print $5,$6,$7,$8,$9,$10,$11,$12,$13}'
else
echo "NO DISPONIBLE"
fi
;;



esac

#sudo fdisk -l | grep EFI | awk '{print $1,$6,$7}'
#sudo fdisk -l | grep /dev/ | awk '{if (NR!=1) {print}}' | sed 's/*//g' | awk -F ' ' '{print $1}' | grep /dev/ | awk '{if (NR=1) {print}}' | sed 's/*//g' | awk -F ' ' '{print $1}'

#cat /etc/locale.gen | grep ".UTF-8 UTF-8" | sed '1,4d' | sed 's/\(.\{1\}\)//'
#localectl list-x11-keymap-layouts | awk '$locales=$locales'
#localectl list-keymaps | awk '$locales=$locales'


# echo Idioma: $(curl https://ipapi.co/languages | awk -F "," '{print $1}')
# echo Ubicación: $(curl https://ipapi.co/country_name)/$(curl https://ipapi.co/region)

# Ejecutar un comando usando la variable guardada
# ejemplo
# commandline = g_strdup_printf("echo %s" , idioma_select);
# g_shell_parse_argv(commandline, NULL, &command, NULL);
# g_free(commandline);
# g_spawn_async(NULL, command, NULL, G_SPAWN_SEARCH_PATH|G_SPAWN_DO_NOT_REAP_CHILD, NULL, NULL, NULL, NULL);


#/////////////////////////////////////////////////////////////////////////////////
#// CSS
#// box-shadow: 5px 0px 10px 4px alpha(black, 0.40);
#// box-shadow: 0px 0px 2px 1px alpha(#1D1D1D, 10.50);
#// #1794D1
#// #1F4152
#// #080808  Tema
#// #0D0E13
#// #222B33
#// #1A1A1A
#/////////////////////////////////////////////////////////////////////////////////


#//gtk_combo_box_get_active(listwidget);
#//gtk_label_set_label(resultado, output);
#//printf("Active text: %s\n", text);

#// ¿Dónde quiere instalar Arch Linux?

#// utilizar todo el disco.
#// utilizar todo el disco y configurar LVM cifrado