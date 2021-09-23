#!/bin/bash
# Hecho por codigo Cristo
# keymap=$(curl https://ipapi.co/languages | awk -F "," '{print $1}' | sed -e's/.$//' | sed -e's/.$//' | sed -e's/.$//') 
zonahoraria="America/Lima"
locacion="es_PE.UTF-8 UTF-8"
teclado="latam"

diskselect="/dev/sdc (7803MB)"

diskauto="TRUE"
diskautoencryp="FALSE"
diskmanual="FALSE"

partiboot="/dev/sda1 - 250M - EFI"
partiroot="/dev/sdb3 - 402,1G"

partihome="/dev/sda1"
partiswap="No"
partihome="/dev/sdb1"

keyencryp="123"
autologin="FALSE"


user=""
passwduser=""
hostname=""
passwdroot=""

ttyselec="TRUE"
desktopDE="FALSE"
desktopDW="FALSE"
desktop="escritorio/xfce4"

kernel="linux-zen"
video="videonouveau"
shell="zsh"
audio="audiojack"
aur="yay"
bluetooth="bluez"
sandbox="flatpak"
wifi="broadcom-wl"



disk=$(echo ${diskselect} | awk '{printf $1}' ) 
boot=$(echo ${partiboot} | awk '{printf $1}' )
root=$(echo ${partiroot} | awk '{printf $1}' )
swap=$(echo ${partiswap} | awk '{printf $1}' )
home=$(echo ${partihome} | awk '{printf $1}' )



case "$1" in

"language")
locales=$(cat ./text/locale.gen | grep -v "#  " | sed 's/#//g' | sed 's/ UTF-8//g' | grep .UTF-8 | sort | awk '{ printf "FALSE ""\0"$0"\0" }')
locale=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your locale/language.\nThe default is American English 'en_US.UTF-8'." --column Select --column Locale TRUE en_US.UTF-8 $locales)
locale="$locale UTF-8"
printf $locale
;;

"teclado")

layout=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text="Select your layout, a two-character country code" --column Select --column Layout $(localectl list-x11-keymap-layouts | awk '{ printf " FALSE ""\0"$0"\0" }'))
printf $layout
;;

"timezone")

zenity --question --width=300 \
--text="¿ Zona Horaria Automatica ?" --title="Zona Horaria"

if [ "$?" = "0" ]; then {
  zonahoraria=$(curl https://ipapi.co/timezone)
  printf $zonahoraria
}
else {

zones=$(cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "/" | sed "s/\/.*//g" | sort -ud | sort | awk '{ printf " FALSE ""\0"$0"\0" }')

zone=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your country/zone." --column Select --column Zone $zones)

subzones=$(cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "$zone/" | sed "s/$zone\///g" | sort -ud | sort | awk '{ printf " FALSE ""\0"$0"\0" }')

subzone=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your sub-zone." --column Select --column Zone $subzones)

zonahoraria=$zone/$subzone
printf $zonahoraria

}
fi
;;

"infodisk") 
sudo fdisk -l ${disk} |  awk 'BEGIN{FS="bytes"","}{print $1} {print $2}' | grep ":" | sed '3d' | sed '4d' | sed '5d' | sed '3d'
;;

"namedisk") 
echo ${diskselect} | awk '{printf $1}'
;;

"namediskauto") 
echo ${diskselect} 
;;

"listaboot") 
sudo fdisk -l | grep EFI | awk '{print $1,"-",$5,"-",$7}' && echo ${diskselect} | awk '{printf $1}'

;;

"boot") 
echo ${partiboot} | awk '{printf $1}'
;;

"root") 
echo ${partiroot} | awk '{printf $1}'
;;

"swap") 
echo ${partiswap} | awk '{printf $1}'
;;

"partiroot") 
sudo fdisk -l ${disk} | grep /dev/ | awk '{if (NR!=1) {print}}' | sed 's/*//g' | awk -F ' ' '{print $1,"-",$5}'
;;

"partihome") 
echo "No"
sudo fdisk -l | grep /dev/ | awk '{if (NR!=1) {print}}' | sed 's/*//g' | awk -F ' ' '{print $1}' | grep /dev/ | awk '{if (NR=1) {print}}' | sed 's/*//g' | awk -F ' ' '{print $1}'
;;

"partiswap") 
echo "No"
sudo fdisk -l ${disk} | grep swap | sed 's/*//g' | awk -F ' ' '{print $1,"-",$5,"-",$7}'
;;

"gparted") 
sudo gparted ${disk}
;;

esac



# | sed -e's/.$//' borrar ultimo caracter


# setxkbmap -layout es


# loadkeys keymap
# curl https://ipapi.co/languages | awk -F "," '{print $1}' | sed -e's/.$//' | sed -e's/.$//' | sed -e's/.$//'


#mkdir -p /mnt/etc/X11/xorg.conf.d/
#echo -e 'Section "InputClass"\n\tIdentifier "system-keyboard"\n\tMatchIsKeyboard "on"\n\tOption "XkbLayout" "'$layout'"\n\tOption "XkbModel" "'$model'"\n\tOption "XkbVariant" ",'$variant'"\n\tOption "XkbOptions" "grp:alt_shift_toggle"\nEndSection' > /mnt/etc/X11/xorg.conf.d/00-keyboard.conf
#echo KEYMAP=$keymap >> /mnt/etc/vconsole.conf


