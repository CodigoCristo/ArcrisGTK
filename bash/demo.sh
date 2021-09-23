# Getting Timezone

# Getting Locale

layout=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text="Select your layout, a two-character country code" --column Select --column Layout $(localectl list-x11-keymap-layouts | awk '{ printf " FALSE ""\0"$0"\0" }'))

keymap=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text="Select your keymap" --column Select --column Keymap $(localectl list-keymaps | awk '{ printf " FALSE ""\0"$0"\0" }'))



locales=$(cat /etc/locale.gen | grep -v "#  " | sed 's/#//g' | sed 's/ UTF-8//g' | grep .UTF-8 | sort | awk '{ printf "FALSE ""\0"$0"\0" }')
locale=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your locale/language.\nThe default is American English 'en_US.UTF-8'." --column Select --column Locale TRUE en_US.UTF-8 $locales)
locale="$locale UTF-8"

zones=$(cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "/" | sed "s/\/.*//g" | sort -ud | sort | awk '{ printf " FALSE ""\0"$0"\0" }')

zone=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your country/zone." --column Select --column Zone $zones)

subzones=$(cat /usr/share/zoneinfo/zone.tab | awk '{print $3}' | grep "$zone/" | sed "s/$zone\///g" | sort -ud | sort | awk '{ printf " FALSE ""\0"$0"\0" }')

subzone=$(zenity --list --radiolist --height=500 --width=450 --title="$title" --text "Select your sub-zone." --column Select --column Zone $subzones)


echo $locale
echo $zone
echo $subzone


zenity --error --width=200 --height=0 \
--text="Completa la elección"