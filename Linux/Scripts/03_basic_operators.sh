#!/bin/bash

# Arithmetic Operators
A=10
B=20
echo "A = $A"
echo "B = $B"
echo ""
echo "A + B = $(( $A + $B ))"
echo "A - B = $(( $A - $B ))"
echo "A * B = $(( $A * $B ))"
echo "A / B = $(( $A / $B ))"
echo "A % B = $(( $A % $B ))"
echo "A = B = $(( A = $B ))"
echo ""

# Relational Operators
A=10
B=20
echo "A = $A"
echo "B = $B"
echo ""
echo "A == B = $(( $A == $B ))"
echo "A != B = $(( $A != $B ))"
echo "A > B = $(( $A > $B ))"
echo "A >= B = $(( $A >= $B ))"
echo "A < B = $(( $A < $B ))"
echo "A <= B = $(( $A <= $B ))"
echo ""