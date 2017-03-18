#!/bin/bash
grep "OK DOWNLOAD" cdlinux.ftp.log | cut -d '"' -f 2,4 | sort | uniq | cut -d '"' -f 2 | sed "s#.*/##" | grep '\.iso' > plik1.txt

grep " 200" cdlinux.www.log | cut -d " " -f 1,7,9 | sort | uniq | cut -d " " -f 1,2 |grep "\.iso" | sort | uniq | sed "s#.*/##" | sed "s#iso.*#iso#" >> plik1.txt
sort plik1.txt | uniq -c
