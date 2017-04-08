#!/bin/bash
MSG1=`dialog --stdout --title "Witaj!" --backtitle "Duzy skrypt - Wyszukiwarka plików .mp3 po tagach id3 -- Program do ustawiania tagów id3 ..." --msgbox "Wcisnij ENTER aby kontynuowac" 8 40 `
echo $MSG1

MENU=`dialog --stdout --title "Wyszukiwarka" --menu "Menu" 10 60 5 "1" "Ustaw tagi" "2" "Wyszukaj po tagach" "3" "Wyjdz"`

if [ $MENU -eq 1 ] ; then

NAZWAPLIKU=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj nazwe pliku " 8 60 `

SCIEZKA=`find /home/ -iname $NAZWAPLIKU 2>/dev/null`

if [ -z $SCIEZKA ] ; then
dialog --title "Blad" --infobox "Nie ma takiego pliku!" 8 40
else 
chmod 777 $WYNIK

MENU2=`dialog --stdout --title "Ustawianie informacji o pliku:" --menu "Menu" 15 60 5 "1" "Ustaw artyste" "2" "Ustaw nazwe albumu" "3" "Ustaw nazwe piosenki" "4" "Ustaw rok" "5" "Ustaw numer sciezki"`

case "$MENU2" in
"1") OPCJA=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj nazwe artysty" 8 60 ` 
id3v2 -a $OPCJA $SCIEZKA;;
"2") OPCJA=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj nazwe albumu" 8 60 ` 
id3v2 -A $OPCJA $SCIEZKA;;
"3") OPCJA=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj nazwe piosenki" 8 60 `
id3v2 -t $OPCJA $SCIEZKA;;
"4") OPCJA=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj rok" 8 60 `
id3v2 -y $OPCJA $SCIEZKA;;
"5") OPCJA=`dialog --stdout --title "Ustawianie tagów" --inputbox "Podaj numer sciezki" 8 60 `
id3v2 -T $OPCJA $SCIEZKA;;
esac

dialog --clear
echo "Super!"
id3v2 -C $SCIEZKA
fi

elif [ $MENU -eq 2 ] ; then

MENU3=`dialog --stdout --title "Ustawianie informacji o pliku:" --menu "Menu" 15 60 5 "1" "Podaj artyste" "2" "Podaj nazwe albumu" "3" "Podaj nazwe piosenki" "4" "Podaj rok" "5" "Podaj numer sciezki"`

case "$MENU3" in
"1") OPCJA=`dialog --stdout --title "Wyszukiwanie po tagach" --inputbox "Szukaj po artyscie" 8 60 `;;
"2") OPCJA=`dialog --stdout --title "Wyszukiwanie po tagach" --inputbox "Szukaj po albumie" 8 60 `;;
"3") OPCJA=`dialog --stdout --title "Wyszukiwanie po tagach" --inputbox "Szukaj po nazwie piosenki" 8 60 `;;
"4") OPCJA=`dialog --stdout --title "Wyszukiwanie po tagach" --inputbox "Szukaj po roku wydania" 8 60 `;;
"5") OPCJA=`dialog --stdout --title "Wyszukiwanie po tagach" --inputbox "Szukaj po numerze sciezki" 8 60 `;;
esac

find /home/ -name "*.mp3" 2>/dev/null > tmp.txt
chmod 777 tmp.txt
touch tmp2.txt
chmod 777 tmp2.txt
while read PATH; do
`id3v2 -R $PATH >> tmp2.txt`
done <tmp.txt

WYNIK=`grep $OPCJA tmp2.txt`
if [ -n $WYNIK ] ; then
dialog --title "Blad" --infobox "Znaleziono!" 8 40
else
dialog --title "Blad" --infobox "Nie znaleziono!" 8 40
fi

#id3v2 -C $SCIEZKA

else echo "Koniec programu!"

fi
