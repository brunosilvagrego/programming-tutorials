#!/bin/bash

IDX=$1

for (( c=1; c<=IDX; c++ ))
do
    STR=$(top -b -c -n 1 | grep /usr/bin/gnome-shell | head -n1)

    echo -e "$STR" | awk '{print $9}' | sed s/,/./g >> cpu-log.txt
    echo -e "$STR" | awk '{print $10}' | sed s/,/./g >> mem-log.txt
done

echo "/usr/bin/gnome-shell CPU usage:"
cat cpu-log.txt
echo

echo "/usr/bin/gnome-shell MEM usage:"
cat mem-log.txt
echo

rm "cpu-log.txt"
rm "mem-log.txt"