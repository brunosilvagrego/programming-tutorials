#!/bin/bash

# Script Parameters
echo "Hello $1 $2"

# Function Definition
Hello () {
    echo "Hello $1 $2"  # Function parameters overload script parameters

    return 1
}

# Invoke function
Hello Bruno Grego

# Capture the value returned by the last executed command
RET=$?
echo "Hello return value = $RET"

# Nested Function
HelloBW () {
    Hello Beautiful World
}

HelloBW