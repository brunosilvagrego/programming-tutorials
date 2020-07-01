'''
It's a good practice to define classes in separate files and import them in the
main program file using the import statement.
'''
# Employee class
class Employee:
    'Common base class for all employees'   # Optional class documentation string
    empCount = 0

    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        Employee.empCount += 1
   
    def displayCount(self):
        print("Total Employees: %d" % Employee.empCount)

    def displayEmployee(self):
        print("Name:", self.name,  ", Salary:", self.salary)


# Create first object of Employee class
emp1 = Employee("Zara Larsson", 2000)
emp1.displayEmployee()
print()

# Create second object of Employee class
emp2 = Employee("John Smith", 5000)
emp2.displayEmployee()
print()

# Display number of employees
print("Total Employees: %d" % Employee.empCount)
# OR
emp1.displayCount()
print()

# Modify class attributes
print(hasattr(emp1, 'salary'))  # Returns true if 'salary' attribute exists
print(getattr(emp1, 'salary'))  # Returns value of 'salary' attribute
setattr(emp1, 'salary', 7000)   # Set attribute 'salary' at 7000
emp1.displayEmployee()
delattr(emp1, 'salary')         # Delete attribute 'salary'
print()

# Built-In class attributes
print("Employee.__doc__:", Employee.__doc__)
print("Employee.__name__:", Employee.__name__)
print("Employee.__module__:", Employee.__module__)
print("Employee.__bases__:", Employee.__bases__)
print("Employee.__dict__:", Employee.__dict__ )
print()

# Point class
class Point:
    # Class constructor
    def __init__( self, x=0, y=0):
        self.x = x
        self.y = y

    # Class destructor
    def __del__(self):
        class_name = self.__class__.__name__
        print(class_name, "destroyed")

# Create object references
pt1 = Point()
pt2 = pt1
pt3 = pt1

# Print obejcts IDs
print(id(pt1), id(pt2), id(pt3))
print()

# Destroying Objects - Garbage Collection
del pt1
del pt2
del pt3
print()

# Class Inheritance
'''
The child class inherits the attributes of its parent class(es), and it can use those attributes
as if they were defined in the child class. A child class can also override data members and methods
from the parent class.
'''
# Define parent class
class Parent:
    parentAttr = 100

    def __init__(self):
        print("Calling parent constructor")

    def parentMethod(self):
        print('Calling parent method')

    def setAttr(self, attr):
        Parent.parentAttr = attr

    def getAttr(self):
        print("Parent attribute :", Parent.parentAttr)

    def hello(self):
        print("Hello, I\'m the Parent class")

# Define child class
class Child(Parent):    
    def __init__(self):
        print("Calling child constructor")

    def childMethod(self):
        print('Calling child method')

    # Overrides Parent class method
    def hello(self):
        print("Hello, I\'m the Child class")

c = Child()         # Instance of Child class
c.childMethod()     # Child calls its method
c.parentMethod()    # Child calls Parent's method
c.setAttr(200)      # Child calls Parent's method
c.getAttr()         # Child calls Parent's method
c.hello()           # Child calls overridden method
print()

# Base Overloading Methods
'''
__init__(self [,args...])
__del__(self)
__repr__(self)
__str__(self)
__cmp__(self, x)
'''

# Overloading Operators
class Vector:
    def __init__(self, a, b):
        self.a = a
        self.b = b

    def __str__(self):
        return "Vector (%d, %d)" % (self.a, self.b)
   
    def __add__(self,other):
        return Vector(self.a + other.a, self.b + other.b)

v1 = Vector(2,10)
v2 = Vector(5,-2)
print(v1 + v2)
print()

# Data Hiding
'''
Attributes named with a double underscore prefix will not be directly visible to outsiders.
'''
class Counter:
    __count = 0
  
    def count(self):
        self.__count += 1
        print(self.__count)

c = Counter()
c.count()
c.count()
# print(c.__count)  # Error, __count can't be accessed directly
print (c._Counter__count)