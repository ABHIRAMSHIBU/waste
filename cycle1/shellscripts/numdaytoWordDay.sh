#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
if [ $# -ne 1 ]
then
	echo "There should be atleast one argument!"
	exit
fi
case $1 in
    1)
        echo Sunday? ;;
    2)
        echo Monday? ;;
    3)
        echo Tuesday? ;;
    4)
        echo Wednesday? ;;
    5)
        echo Thursday? ;;
    6)
        echo Friday? ;;
    7)
        echo Saturday? ;;
    *)
	echo Please reboot your brain! ;;

esac

