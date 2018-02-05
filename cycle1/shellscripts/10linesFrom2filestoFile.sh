#!/usr/bin/env bash
# Copyright 2018 Abhiram
if [ $# -eq 1 ]
then
	printf "Enter the name of first file:"
	read f1
	printf "Enter the name of second file:"
	read f2
	head $f1 > /tmp/file1
	head $f2 > /tmp/file2
	cat /tmp/file1 /tmp/file2 > $1
	rm /tmp/file1 /tmp/file2
else
	echo "Sorry you need to pass one argument!"
fi
