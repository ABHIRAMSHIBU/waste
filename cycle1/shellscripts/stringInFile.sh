#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
if [ $# -ne 1 ]
then
	echo "There should be atleast one argument!"
	exit
fi
if [ ! -f $1 ]
then
	echo "File should exist *_*"
	exit
fi
printf "Enter a string to search :"
read string
grep $string $1 > /dev/null
if [ $? -eq 1 ]
then
	echo "String not found!"
else
	echo "String found!"
fi
