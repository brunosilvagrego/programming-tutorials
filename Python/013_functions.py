# Regular Functions #
'''
All parameters (arguments) in Python are passed by reference. The called function may change the original objects
passed as parameters.
'''
# Function definition
def incrementList (listObject):
    "This function increments all values in an integer list"    # Optional documentation string
    i = 0
    while (i < len(listObject)):
        listObject[i] = listObject[i] + 1
        i = i + 1
    
    return

# Function call
list1 = [1, 2, 3, 4, 5]
print("Original list1    = ", list1)
incrementList(list1)
print("list1 Incremented = ", list1)
print()


# Required Arguments #
'''
The number of arguments in the function call should match exactly with the function definition.
'''
# incrementList() -> syntax error


# Keyword Arguments #
'''
When the caller identifies the arguments by the parameter name, the arguments can be out of order.
'''
# Function definition
def printInfo (name, age):
    print("Name: ", name)
    print("Age:  ", age)
    return

# Function call
printInfo(age = 23, name = "John Smith")
print()


# Default Arguments #
'''
A default argument assumes a default value if a value is not provided in the function call. 
'''

# Function definition
def printInfoDefault (name, age = 35):
    print("Name: ", name)
    print("Age:  ", age)
    return

# Function call
printInfoDefault(age = 23, name = "John Smith")
printInfoDefault(name = "John Smith")
print()


# Variable-length Arguments #
'''
An asterisk (*) is placed before the variable name that holds the values of all nonkeyword variable arguments.
This tuple remains empty if no additional arguments are specified during the function call.
'''
# Function definition
def printInfoVar (par1, *vartuple):
    print(par1)
   
    for var in vartuple:
        print(var)

    return

# Function Call
printInfoVar('John Smith')
printInfoVar(23, 'Student', 'Computer Science')
print()


# Anonymous Functions #
'''
Anonymous functions are not declared in the standard manner by using the def keyword. You can use the lambda keyword
to create small anonymous functions.
'''
# Function definition
sum = lambda arg1, arg2: arg1 + arg2

# Function call
print("sum(10, 20) = ", sum(10, 20))
print("sum(20, 30) = ", sum(20, 30))
print()


# return Statement #
'''
The return statement exits a function, optionally passing back an expression to the caller.
A return statement with no arguments is the same as return None.
'''
# Function definition
def sumList (listObject):
    total = 0

    for var in listObject:
        total += var

    return total

# Function call
print("sumList(list1) = ", sumList(list1))
print()

# Local and Global Variables
'''
Local variables can be accessed only inside the function in which they are declared, whereas global variables
can be accessed throughout the program body by all functions.
'''
result = 0   # Global variable

# Function definition
def diff (arg1, arg2):
   result = arg1 - arg2;    # Local variable
   print("Local variable result  = ", result)
   return result

# Function call
diff(20, 5)
print("Global variable result = ", result)
print()