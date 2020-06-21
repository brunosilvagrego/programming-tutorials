# Strings #
'''
Python treats single quotes the same as double quotes. Creating strings is as simple as assigning a value to a variable.
Python does not support a character type. Characters are treated as strings of length one.
In Python 3 all strings are represented in Unicode
'''
str1 = 'Hello World!'
str2 = "Python Programming"

print(str1)
print(str2)
print()

# Updating Strings #
str1 = str1[:6] + str2[0:6]
print("Updated String = ", str1)
print()

# String Special Operators #
print("str1 + str2 = ", str1 + str2)
print("str1 * 2 = ", str1 * 2)
print("str1[0] = ", str1[0])
print("str2[1:5]: ", str2[1:5])
print("H in str1 = ", "H" in str1)
print("H not in str1 = ", "H" not in str1)
print()

# String Formatting Operator #
print("My name is %s and I am %d years old" % ("John Smith", 23))
print()

# Triple Quotes #
'''
Python's triple quotes allow strings to span multiple lines, including verbatim NEWLINEs, TABs, and any other
special characters. The syntax for triple quotes consists of three consecutive single or double quotes.
'''
str3 = """This is a long string that is made up of
several lines and non-printable characters such as
TAB ( \t ). NEWLINEs within the string may appear
within brackets [ \n ] or within
the variable assignment."""
print(str3)
print()

# Raw String #
print('C:\\nowhere')
print(r'C:\\nowhere')
print()

# Built-in String Methods #
str = "example string"
print("str = ", str)
print("len(str) = ", len(str))
print()

# capitalize()
print("str.capitalize() = ", str.capitalize())
print()

# center()
print("str.center(40, '-') = ", str.center(40, '-'))
print()

# count()
print("str.count('e') = ", str.count('e'))
print()

# isalnum()
str4 = "this2020"
print("str = ", str)
print("str.isalnum() = ", str.isalnum())
print("str4 = ", str4)
print("str4.isalnum() = ", str4.isalnum())
print()

# isalpha()
str4 = "this"
print("str = ", str)
print("str.isalpha() = ", str.isalpha())
print("str4 = ", str4)
print("str4.isalpha() = ", str4.isalpha())
print()

# isdigit()
str4 = "123456789"
print("str = ", str)
print("str.isdigit() = ", str.isdigit())
print("str4 = ", str4)
print("str4.isdigit() = ", str4.isdigit())
print()

# islower()
str4 = "Example String"
print("str = ", str)
print("str.islower() = ", str.islower())
print("str4 = ", str4)
print("str4.islower() = ", str4.islower())
print()

# isspace()
str4 = "       "
print("str = ", str)
print("str.isspace() = ", str.isspace())
print("str4 = ", str4)
print("str4.isspace() = ", str4.isspace())
print()

# istitle()
str4 = "Example String"
print("str = ", str)
print("str.istitle() = ", str.istitle())
print("str4 = ", str4)
print("str4.istitle() = ", str4.istitle())
print()

# isupper()
str4 = "EXAMPLE STRING"
print("str = ", str)
print("str.isupper() = ", str.isupper())
print("str4 = ", str4)
print("str4.isupper() = ", str4.isupper())
print()

# lower()
str4 = "EXAMPLE STRING"
print("str = ", str)
print("str.lower() = ", str.lower())
print("str4 = ", str4)
print("str4.lower() = ", str4.lower())
print()

# upper()
str4 = "EXAMPLE STRING"
print("str = ", str)
print("str.upper() = ", str.upper())
print("str4 = ", str4)
print("str4.upper() = ", str4.upper())
print()

# title()
str4 = "EXAMPLE STRING"
print("str = ", str)
print("str.title() = ", str.title())
print("str4 = ", str4)
print("str4.title() = ", str4.title())
print()

# swapcase()
str4 = "Example String"
print("str = ", str)
print("str.swapcase() = ", str.swapcase())
print("str4 = ", str4)
print("str4.swapcase() = ", str4.swapcase())
print()

# split()
print("str = ", str)
print("str.split() = ", str.split())
print("str.split('e') = ", str.split('e'))
print("str.split('e', 1) = ", str.split('e', 1))
print()