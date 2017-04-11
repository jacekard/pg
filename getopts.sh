#!/bin/bash
# Author           : Imie Nazwisko ( email )
# Created On       : data
# Last Modified By : Imie Nazwisko ( email )
# Last Modified On : data 
# Version          : wersja
#
# Description      :
# Opis
#
# Licensed under GPL (see /usr/share/common-licenses/GPL for more details
# or contact # the Free Software Foundation for a copy)

#DOŁĄCZANIE ZEWNETRZNEJ 'Biblioteki' zmiennych, funkcji, do których można się odwołać
. skrypt.rc
####

while getopts hvf:q  OPT; do
  case $OPT in
   h) echo "Pomoc";;
   v) echo "Wersja";;
   f) PLIK=$OPTARG
      echo $PLIK;;
   q) echo "Koniec"
      exit;;
   *) echo "Nieznana opcja";;
  esac
done

## getopts zmienna: = zmienna z dwukropkiem po niej przyjmuje argument $OPTARG (bez ':' nie działa!)


# Dodać do dużego skryptu "getopts" z parametrami -h -v (help i version)
# PLIK TYMCZASOWY NAZWAĆ TMP+NAZWA TEGO PROCESU:

#ZMIENNA '$$' trzyma numer procesu
$ZMIENNA > /tmp/165178.$$
rm /tmp/165178.$$

