#!/bin/sh

programasbase=$(cat ../program/utilidades |  awk '{ printf " TRUE  ""\0"$0"\0" }')

programasbase=$(zenity --list  --checklist --height=500 --width=400 --window-icon="../iconos/iconoinstalador.png" --title="Sistema Base" --text "base y base-devel vienen por defecto instalado \n\nDesmarca el paquete que no desees" --column "Select" --column "Driver" $programasbase)


touch ../program/selectprogram
echo $programasbase > ../program/selectprogram
sed -i 's/|/\n/g' "../program/selectprogram"

programasbase=$(cat ../program/selectprogram |  awk '{ print "sudo pacman -S ""\0"$0" --noconfirm &&" }')  

echo "#!/bin/bash" > ../program/selectprogram
echo $programasbase >> ../program/selectprogram

sed -i 's/&&/\n/g' "../program/selectprogram"

sudo sh ../program/selectprogram