#!/usr/bin/env bash
# Copyleft 2018 Abhiram
if [ $# -eq 1 ]
then

	a=$(find $1* -type f  | wc -l )
	echo $a
else
	echo "Sorry you need to pass one arguments!"
fi
