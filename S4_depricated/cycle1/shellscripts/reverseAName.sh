#!/usr/bin/env bash
printf "Get user name of current user?[Y/y/n/N] :"
read choice
if  test $choice = 'y'  ||  test $choice = 'Y'
then
	printf "String in reverse :"
        echo $(whoami) | rev
        printf "Count of chars including new line :"
        echo $(whoami) | wc -c
else
	printf "Enter a name :"
	read name
	printf "String in reverse :"
	echo $name | rev
	printf "Count of chars including new line :"
	echo $name | wc -c
fi
