#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
printf "Enter source file name :"
read source
printf "Enter destination file name :"
read dest
cat $source | sed 'y/aeiou/AEIOU/' > $dest
