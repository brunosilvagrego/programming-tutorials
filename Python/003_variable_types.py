# Assigning Values to Variables
counter = 100        # An integer assignment
miles   = 1000.0     # A floating point
name    = "John"     # A string

print(counter)
print(miles)
print(name)
print("")

# Multiple Assignment
a = b = c = 1
print(a)
print(b)
print(c)
print("")

a, b, c = 1, 2, "John"
print(a)
print(b)
print(c)
print("")

# Delect objects
del a, b, c

# Numbers
'''
All integers in Python3 are represented as long integers. There is no separate number type as long.
'''
a = 10      # int
b = 15.2    # float
c = 3.14j   # complex

print(a)
print(b)
print(c)
print("")

# Strings
str = 'Hello World!'

print(str)          # Prints complete string
print(str[0])       # Prints first character of the string
print(str[2:5])     # Prints characters starting from 3rd to 5th
print(str[2:])      # Prints string starting from 3rd character
print(str * 2)      # Prints string two times
print(str + "TEST") # Prints concatenated string
print("")

# Lists
'''
Lists are similar to arrays in C. One of the differences between them is that all the items belonging to a list
can have different data type.
'''
myList = [ 'abcd', 786 , 2.23, 'john', 70.2 ]
tinylist = [123, 'john']

print(myList)             # Prints complete list
print(myList[0])          # Prints first element of the list
print(myList[1:3])        # Prints elements starting from 2nd till 3rd 
print(myList[2:])         # Prints elements starting from 3rd element
print(tinylist * 3)       # Prints list three times
print(myList + tinylist)  # Prints concatenated lists
print("")

# Tuples
'''
Lists are enclosed in brackets ( [ ] ) and their elements and size can be changed, while tuples are enclosed in
parentheses ( ( ) ) and cannot be updated. Tuples can be thought of as read-only lists
'''
myTuple = ( 'abcd', 786 , 2.23, 'john', 70.2  )
tinyTuple = (123, 'john')

print(myTuple)               # Prints complete tuple
print(myTuple[0])            # Prints first element of the tuple
print(myTuple[2:4])          # Prints elements starting from 3rd till 4th 
print(myTuple[3:])           # Prints elements starting from 4th element
print(tinyTuple * 2)         # Prints tuple two times
print(myTuple + tinyTuple)   # Prints concatenated tuple
print("")

# Dictionaries
'''
Dictionaries work like associative arrays or hashes found in Perl and consist of key-value pairs.
Dictionaries have no concept of order among the elements.
'''
dict1 = {}
dict1['one'] = "This is one"
dict1[2] = "This is two"

dict2 = {'name': 'john','code':6734, 'dept': 'sales'}

print(dict1['one'])    # Prints value for 'one' key
print(dict1[2])        # Prints value for 2 key
print(dict2)           # Prints complete dictionary
print(dict2.keys())    # Prints all the keys
print(dict2.values())  # Prints all the values
print("")

# Data Type Conversion
num_int = 123
num_str = "456"

print("Data type of num_int:", type(num_int))
print("Data type of num_str before Type Casting:", type(num_str))

num_str = int(num_str)
print("Data type of num_str after Type Casting:", type(num_str))

num_sum = num_int + num_str

print("Sum of num_int and num_str:", num_sum)
print("Data type of the sum:", type(num_sum))