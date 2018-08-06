#!/usr/bin/env bash
. colors.sh
function start() {
    echo
    echo -e $RED"Question $(($1 + 1))"$RESET
    return $(($1 + 1))
}
start 0
count=$?
awk '/P/' text
start $count
count=$?
awk '/P/{print $1;}' text
start $count
count=$?
awk '/P/{print $2;}' text
start $count
count=$?
awk '{if ($1 ~ /a$/ || $1 ~ /P/) print $1;} ' text
start $count
count=$?
awk '/P|A/{print $1}' text
start $count
count=$?
awk '$2 > 40{print $1}' text
start $count
count=$?
awk '!/P/{print $1}' text
start $count
count=$?
awk '{if ($1 ~ /a$/ && $1 ~ /P/) print $1;} ' text
start $count
count=$?
awk '/P|$2>26/{print $1}' text
start $count
count=$?
awk '$1 ~ /a$|e$|i$|o$|u$/{print $1}' text
