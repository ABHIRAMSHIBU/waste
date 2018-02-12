#!/usr/bin/env bash
printf "Enter a name :"
read name
printf "String in reverse :"
echo $name | rev
printf "Count of chars including new line :"
echo $name | wc -c
