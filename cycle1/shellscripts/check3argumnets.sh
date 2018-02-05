#!/usr/bin/env bash
# Copyright 2018 Abhiram
if [ $# -eq 3 ]
then
	echo "There are three argumnets!"
	#test $1 = $2
	#a=$?
	#if [ $a -eq 1 ]
	#then
	#	echo "They are diffrent"
	#else
	#	echo "They are same"
	#fi
else
	echo "Sorry there are "$#" arguments"
fi
