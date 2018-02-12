#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
. colors.sh
echo -e "$RED--------------------------MENU------------------------"
echo -e "$GREEN        Menu driven program for displaying day!"
echo "  1) Sunday"
echo "  2) Monday"
echo "  3) Tuesday"
echo "  4) Wednesday"
echo "  5) Thursday "
echo "  6) Friday "
echo "  7) Saturday "
echo -e "$RED======================================================"
echo -e $RESET
printf "Enter a choice :"
read choice
echo -e $GREEN
case $choice in
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
echo -e $RESET
