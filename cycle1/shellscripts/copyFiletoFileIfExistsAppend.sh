#!/usr/bin/env bash
# Copyleft 2018 Abhiram
if [ $# -eq 2 ]
then
	cat $1 >> $2
else
	echo "Sorry you need to pass two argument!"
fi
