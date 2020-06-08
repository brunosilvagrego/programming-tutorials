#!/bin/bash

echo "Line 1" > temp.txt
echo "Line 2" >> temp.txt
echo "Line 3" >> temp.txt
echo "Line 4" >> temp.txt
echo "Line 5" >> temp.txt
echo "/Line 6" >> temp.txt

echo "cat temp.txt"
cat temp.txt
echo -e "\n\n"

# sed - stream editor

# Deleting all lines
echo "cat temp.txt | sed 'd'"
cat temp.txt | sed 'd'
echo -e "\n\n"

# Deleting all lines 
echo "sed -e 'd' temp.txt"
sed -e 'd' temp.txt
echo -e "\n\n"

# sed Adresses
echo "cat temp.txt | sed '1, 3d' | more"
cat temp.txt | sed '1, 3d' | more
echo -e "\n\n"

# sed Adresses
echo "cat temp.txt | sed '3, 5d' | more"
cat temp.txt | sed '3, 5d' | more
echo -e "\n\n"

# sed Adresses
echo "cat temp.txt | sed '1, 3p'"
cat temp.txt | sed '1, 3p'
echo -e "\n\n"

# sed Adresses
echo "cat temp.txt | sed -n '1, 3p'"
cat temp.txt | sed -n '1, 3p'
echo -e "\n\n"

# Substitution
echo "cat temp.txt | sed 's/Line/String/'"
cat temp.txt | sed 's/Line/String/'
echo -e "\n\n"

# Substitution
echo "cat temp.txt | sed 's:/Line:String:'"
cat temp.txt | sed 's:/Line:String:'
echo -e "\n\n"

# Substitution
echo "cat temp.txt | sed 's/Line//'"
cat temp.txt | sed 's/Line//'
echo -e "\n\n"

# Substitution
echo "cat temp.txt | sed '5s/Line/Test/'"
cat temp.txt | sed '5s/Line/Test/'
echo -e "\n\n"

# Matching
echo "cat temp.txt | sed -n '/4/p'"
cat temp.txt | sed -n '/4/p'
echo -e "\n\n"

# Regular Expression - Delete all lines beginning with "Line"
echo "cat temp.txt | sed '/^Line/d'"
cat temp.txt | sed '/^Line/d'
echo -e "\n\n"

# Regular Expression - Delete all lines ending with "5"
echo "cat temp.txt | sed '/5$/d'"
cat temp.txt | sed '/5$/d'
echo -e "\n\n"

# Ampersand Referencing
echo "cat temp.txt | sed -e 's/[[:digit:]]$/(&)/g'"
cat temp.txt | sed -e 's/[[:digit:]]$/(&)/g'
echo -e "\n\n"

# Using multiple sed commands
echo "cat temp.txt | sed -e 's/[[:digit:]]$/(&)/g' -e 's/Line/String/'"
cat temp.txt | sed -e 's/[[:digit:]]$/(&)/g' -e 's/Line/String/'
echo -e "\n\n"

# Back referencing
echo "cat temp.txt | sed 's/\(.*e\)\(.*$\)/First String: \1 Number: \2/'"
cat temp.txt | sed 's/\(.*e\)\(.*$\)/First String: \1; Number:\2/'
echo -e "\n\n"

rm temp.txt