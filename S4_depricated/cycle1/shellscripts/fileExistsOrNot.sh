#!/usr/bin/env bash
# Copyleft 2018 Abhiram
if [ $# -eq 1 ]
then
	if [ -f $1 ]
	then
		echo "File exists!"
	else
		echo "File dont exist"
	fi
	#test $1 = $2
	#a=$?
	#if [ $a -eq 1 ]
	#then
	#	echo "They are diffrent"
	#else
	#	echo "They are same"
	#fi
else
	echo "Sorry you need to pass one argument!"
fi
