#!/bin/bash
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
