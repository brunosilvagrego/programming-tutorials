#!/bin/bash

# Relational operators
# '-eq' <=> '=='
# '-ne' <=> '!='
# '-gt' <=> '>'
# '-lt' <=> '<'
# '-ge' <=> '>='
# '-le' <=> '<='

# The -e option enables the interpretation of backslash escapes
I=100
echo -e "Value of I is $I\n"

# The -n option disables the insertion of a new line
I=2000
echo -n "Value of I is $I"

echo
echo

# Assign a command output to a variable => $(command)
TEMP=$(date)
echo $TEMP

echo

# Metacharacters: * ? [ ] ' " \ $ ; & ( ) | ^ < > new-line space tab

# Without \ the command would report an error
echo Hello\; World

echo

echo It\'s Shell Programming

echo

# Variable Substitution
# ${var:-word} => If var is null or unset, word is substituted for var. The value of var does not change.
echo ${var:-"Variable is not set"}
echo "1 - Value of var is ${var}"
echo

# ${var:=word} => If var is null or unset, var is set to the value of word.
echo ${var:="Variable is not set"}
echo "2 - Value of var is ${var}"
echo

# ${var:+word} => If var is set, word is substituted for var. The value of var does not change.
echo ${var:+"Value set by :="}
echo "3 - Value of var is $var"
echo

# ${var:?message} => If var is null or unset, message is printed to standard error. This checks that variables are set correctly.
unset var
echo ${var:?"value not set"}
echo