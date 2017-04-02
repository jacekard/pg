#!/bin/bash

option(){
OPTION=`zenity --list --column=Menu "${MENU[@]}" --width 300 --height 450`
}

while [ "$OPTION" != "Koniec" ]
do

 MENU=("Nazwa pliku: $PLIK" "Katalog: $KATALOG" "Min rozmiar: $MIN"  "Max rozmiar: $MAX" "Zawartosc: $ZAW" "Szukaj" "Koniec")
   clear
   option
   case $OPTION in
       "Nazwa pliku: "*) PLIK=`zenity --entry --text "Podaj nazwe"`;;
       "Katalog: "*) KATALOG=`zenity --entry --text "Podaj katalog"`;;
       "Min rozmiar: "*) MIN=`zenity --entry --text "c/k/M/G"`;;
       "Max rozmiar: "*) MAX=`zenity --entry --text "c/k/M/G"`;;
       "Zawartosc: "*) ZAW=`zenity --entry --text "Podaj zawartosc"`;;
       "Koniec"*) echo "Zakonczenie dzialania";;
   esac
   if [ "$OPTION" == "Szukaj" ]
   then
	CMD="$KATALOG -name $PLIK -size +$MIN -size -$MAX -exec grep -l $ZAW {} \; |& grep -v Brak dostêpu | wc -l" 
	   echo $CMD
   WYNIK=$(find $KATALOG -name $PLIK -size "+$MIN" -size "-$MAX" -exec grep -l $ZAW {} \; |& grep -v "Brak dostêpu" | wc -l)
echo "$WYNIK"
		if [ $WYNIK -gt 0 ];then
		zenity --info --title "Zakonczono szukanie" --text "plik istnieje"
		else
		zenity --info --title "Zakonczono szukanie" --text "plik nie istnieje"
		fi
	
   
   
   fi
   clear
done
