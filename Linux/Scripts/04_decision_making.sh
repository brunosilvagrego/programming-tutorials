#!/bin/bash

# Relational operators
# '-eq' <=> '=='
# '-ne' <=> '!='
# '-gt' <=> '>'
# '-lt' <=> '<'
# '-ge' <=> '>='
# '-le' <=> '<='

A=10
B=20
echo "A = $A"
echo "B = $B"
echo ""

# if then fi
if [ $A -lt $B ]
then
    echo "A is less than B"
fi

echo ""

# if then else fi
if [ $A -eq $B ]
then
    echo "A is equal to B"
else
    echo "A is not equal to B"
fi

echo ""

# if then elif else fi
if [ $A -eq $B ]
then
    echo "A is equal to B"
elif [ $A -gt $B ]
then
    echo "A is greater than B"
elif [ $B -gt $A ]
then
    echo "B is greater than A"
else
    echo "None of the condition met"
fi

echo ""

# case esac
case $1 in
    1) ./01_basics.sh
        ;;
    2) ./02_arrays.sh
        ;;
    3) ./03_basic_operators.sh
        ;;
    *)
        echo "usage: 04_decision_making N"
        echo "1 -> ./01_basics.sh"
        echo "2 -> ./02_arrays.sh"
        echo "3 -> ./03_basic_operators.sh"
        ;;
esac