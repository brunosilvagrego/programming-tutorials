#!/bin/bash

# Relational operators
# '-eq' <=> '=='
# '-ne' <=> '!='
# '-gt' <=> '>'
# '-lt' <=> '<'
# '-ge' <=> '>='
# '-le' <=> '<='

# while do done
I=0

while [ $I -lt 10 ]
do
    echo $I
    ((I++))
done

echo

# Nesting while loops
I=0

while [ $I -lt 10 ]
do
    J=$I
    while [ $J -ge 0 ]
    do
        echo -n "$J "
        ((J--))
    done

    echo
    ((I++))
done

echo


# for do done
for FILE in $HOME/Scripts/*.sh      # <=> for FILE in /home/bruno/Scripts/*.sh
do
    echo $FILE
done

echo

# until do done
I=10

until [ $I -eq 0 ]
do
    echo $I
    ((I--))
done

echo

# select do case esac done
select DRINK in tea coffee water juice appe all none
do
    case $DRINK in
        tea|coffee|water|all)
            echo "Go to canteen"
            ;;
        juice|appe)
            echo "Available at home"
            ;;
        none)
            break
            ;;
        *)
            echo "ERROR: invalid selection"
            ;;
    esac
done

echo

# break
for A in 1 2 3
do
    for B in 0 5
    do
        if [ $A -eq 2 -a $B -eq 0 ]
        then
            break 2     # integer parameter determins the number of nested loops to break
        else
            echo "$A $B"
        fi
    done
done

echo

# continue (can also contain integer parameter)
NUMS="0 1 2 3 4 5 6 7 8 9"

for NUM in $NUMS
do
    ((Q=$NUM%2))
    if [ $Q -eq 0 ]
    then
        echo "$NUM is an even number"
        continue
    fi
    echo "$NUM is an odd number"
done