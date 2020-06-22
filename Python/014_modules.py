'''
A module is a file containing Python code. A module can define functions, classes and variables.
A module can also include runnable code.
'''

import math
import support
import importlib

'''
This statement does not import the entire module functions into the current namespace. It just introduces the
item incrementList from the module functions into the global symbol table of the importing module.
'''
from functions import incrementList

# support.hello()
support.hello()
print()

# support.fib()
print(support.fib(100))
print()

# functions.incrementList()
list1 = [5, 10, 15, 20, 25]
print("Original list1    = ", list1)
incrementList(list1)
print("list1 Incremented = ", list1)
print()

# Namespaces and Scoping
'''
If a local and a global variable have the same name, the local variable shadows the global variable.
In order to assign a value to a global variable within a function it is necessary to use the global statement.
'''
money = 2000

def AddMoney():
    global money
    money = money + 1
    return

print(money)
AddMoney()
print(money)
print()

# dir() Function
'''
The dir() built-in function returns a sorted list of strings containing the names defined by a module.
'''
print("dir(support) = ", dir(support))
print()
print("dir(math) = ", dir(math))
print()

# globals() and locals()
def foo():
    total = 0

    print("globals() = ", globals())
    print()

    print("locals() = ", locals())
    print()

    return

foo()

# reload()
'''
The reload() function can be used to reexecute the top-level code in a module.
'''
importlib.reload(support)
print()

