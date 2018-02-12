#!/usr/bin/env bash
# Copyleft (c) 2018 Abhiram Shibu
printf "Enter first number :"
read a
printf "Enter second number :"
read b
c=$(( $a + $b )) 
echo "Sum is :"$c
c=$(( $a * $b ))
echo "Mult is :"$c
c=$(( $a / $b ))
echo "Div is :"$c
