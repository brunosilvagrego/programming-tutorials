#!/bin/bash

echo "What is your name?"
read PERSON
echo "Hello, $PERSON"

VAL=1000
echo "VAL = $VAL"

# $1 ... $9 are script parameters
echo "Script Name: $0"
echo "First Parameter: $1"
echo "Second Parameter: $2"
echo "Quoted Values: $@"
echo "Quoted Values: $*"
echo "Total Number of Parameters : $#"

for TOKEN in $*
do
   echo $TOKEN
done
