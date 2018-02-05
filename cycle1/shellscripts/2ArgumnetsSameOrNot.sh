#!/usr/bin/env bash
# Copyright 2018 Abhiram
if [ $# -eq 2 ]
then
	grep -n $1 $2 > /dev/null
	a=$?
	if [ $a -eq 1 ]
	then
		echo "String is not present!"
	else
		echo "String is present in that file!"
	fi
else
	echo "Sorry please enter 2 arguments!"
fi
