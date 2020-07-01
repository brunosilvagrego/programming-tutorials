'''
A regular expression is a special sequence of characters that allows to match or find
other strings or sets of strings, using a specialized syntax held in a pattern.
Regular expressions are widely used in UNIX/Linux.

The module re provides full support for Perl-like regular expressions in Python.
The re module raises the exception re.error if an error occurs while compiling or using
a regular expression.
'''

import re

line = "Cats are smarter than dogs"

# re.match()
matchObj = re.match(r'(.*) are (.*?) .*', line, re.M | re.I)

if (matchObj):
    print("matchObj.group(): ", matchObj.group())
    print("matchObj.group(1):", matchObj.group(1))
    print("matchObj.group(2):", matchObj.group(2))
else:
    print("No match!")

print()

# re.search()
searchObj = re.search(r'(.*) are (.*?) .*', line, re.M | re.I)

if (searchObj):
    print("searchObj.group(): ", searchObj.group())
    print("searchObj.group(1):", searchObj.group(1))
    print("searchObj.group(2):", searchObj.group(2))
else:
    print("Nothing found!")

print()

# re.match() vs re.search()
'''
re.match() checks for a match only at the beginning of the string.
re.search() checks for a match anywhere in the string.
'''
matchObj = re.match(r'dogs', line, re.M | re.I)

if (matchObj):
    print("match --> matchObj.group():", matchObj.group())
else:
    print("No match!")

searchObj = re.search( r'dogs', line, re.M | re.I)

if (searchObj):
    print("search --> searchObj.group() : ", searchObj.group())
else:
    print("Nothing found!")

print()

# re.sub()
phone = "2004-959-559 # This is a Phone Number"

# Delete Python-style comments
num = re.sub(r'#.*$', "", phone)
print("Phone Number:", num)

# Remove anything other than digits
num = re.sub(r'\D', "", phone)    
print("Phone Number:", num)

print()