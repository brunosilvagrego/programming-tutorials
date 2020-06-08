#!/bin/bash

# Output Redirection ( >, >> )
ls -l > temp.txt
cat temp.txt
echo

# Overwrite file
echo Test > temp.txt
cat temp.txt
echo

# Append to file
date >> temp.txt
cat temp.txt
echo

# Input Redirection ( < )
wc -l < temp.txt    # count the number of lines in temp.txt
echo

# Here Document ( << )
wc -l << EOF
This is a simple
here document mockup
with 4 lines
of text
EOF

echo

# Discard command output
ls > /dev/null

# Streams:
# 0 => STDIN
# 1 => STDOUT
# 2 => STDERR

# Discard command error output by redirecting STDERR to STDOUT
ls foo > /dev/null 2>&1

# Redirect STDOUT to STDERR
echo "Test" 1>&2

rm temp.txt