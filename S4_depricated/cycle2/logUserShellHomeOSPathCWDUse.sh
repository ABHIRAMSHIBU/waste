#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
#QUESTION - 1. Currently logged user and his login name 2. Your current shell 3.Your home directory 4. Your operating system type 5. Your current path setting 6.Your current working directory 7. Number of users currently logged in
. colors.sh
echo -e "$RED User name: $(id -u -n),$GREEN User ID: $(id -u)$RESET"
echo -e "$GREEN Shell:$RED $SHELL $RESET"
echo -e "$GREEN Home:$RED $HOME $RESET"
echo -e "$GREEN OS:$RED $(uname -o) $RESET"
echo -e "$GREEN Path:$RED $PATH $RESET"
echo -e "$GREEN Current DIR:$RED $PWD $RESET"
echo -e "$GREEN Shell:$RED $SHELL $RESET"
echo -e "$GREEN Logged Users:$RED $(who | wc -l) $RESET"
echo -e "Logged in users may replicate according to number of shells "
