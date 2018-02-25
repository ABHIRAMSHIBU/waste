#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
. colors.sh
function sum(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 + $2 ))
	fi
}
function substract(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 - $2 ))
	fi
}
function multiply(){
	if [ $# -eq 2 ]
	then
		echo $(( $1 * $2 ))
	fi
}
function devide(){
	if [ $# -eq 2 ]
        then
                echo $(( $1 / $2 ))
    fi
}
function mod(){
    if [ $# -eq 2 ]
        then
                echo $(( $1 % $2 ))
    fi
}
c=1
while [ $c -eq 1 ]
do
    clear
    echo -e "$RED---------------------------Main Menu---------------------------------$RESET"
    echo -e "$GREEN      1) Add"
    echo "      2) Substract"
    echo "      3) Multiply"
    echo "      4) Divide"
    echo "      5) Mod"
    echo -e "$RED=====================================================================$RESET"
    c=0
    printf "Enter a choice :"
    read choice
    if [ $choice -eq 1 ]
    then
        printf "Enter first number to add :"
        read a
        printf "Enter second number to add :"
        read b
        printf "Answer is :"
        sum $a $b
    else
        if [ $choice -eq 2 ]
        then
            printf "Enter first number to substract :"
            read a
            printf "Enter second number to substract :"
            read b
            printf "Answer is :"
            substract $a $b
        else
            if [ $choice -eq 3 ]
            then
                printf "Enter first number to multiply :"
                read a
                printf "Enter second number to multiply :"
                read b
                printf "Answer is :"
                multiply $a $b
            else
                if [ $choice -eq 4 ]
                then
                    printf "Enter first number to devide :"
                    read a
                    printf "Enter second number to devide :"
                    read b
                    printf "Answer is :"
                    devide $a $b
                else
                    if [ $choice -eq 5 ]
                    then
                        printf "Enter first number to mod :"
                        read a
                        printf "Enter second number to mod :"
                        read b
                        printf "Answer is :"
                        mod $a $b
                    else
                        echo -e "$RED Enter a valid input and try again!$RESET"
                    fi
                fi
            fi
        fi
    fi
    printf "Do you want to exit [0-exit, 1-continue]:"
    read c
done
