#!/usr/bin/env bash
# Copyleft 2018 Abhiram Shibu
printf "Enter N :"
read N
sum=0;
printf "Do you want to enter numbers?[y/Y/n/N] :"
read choice
if  test $choice = 'y'  ||  test $choice = 'Y'
then
	while [ ! $N -eq 0 ]
	do
		printf "Enter number :"
		read num
		sum=$(( $sum + $num ))
		N=$(( N - 1 ))
	done
else
	printf "Finding sum of n numbers \n"
	while [ ! $N -eq 0 ]
        do
                sum=$(( $sum + $N ))
                N=$(( N - 1 ))
        done
fi
echo "The sum is :"$sum
