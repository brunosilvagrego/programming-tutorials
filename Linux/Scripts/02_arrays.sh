#!/bin/bash

# String Array
NAME=(Bruno Alexandre da Silva Grego)

echo "NAME[0] = ${NAME[0]}"
echo "NAME[1] = ${NAME[1]}"
echo "NAME[2] = ${NAME[2]}"
echo "NAME[3] = ${NAME[3]}"
echo "NAME[4] = ${NAME[4]}"

echo "NAME[*] = ${NAME[*]}"
echo "NAME[@] = ${NAME[@]}"

# Integer Array
ARRAY[0]=2
ARRAY[1]=4
ARRAY[2]=6
ARRAY[3]=8
ARRAY[4]=10

echo " "
echo "Integer ARRAY:"

for i in "${ARRAY[@]}"; do echo "$i"; done