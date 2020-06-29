import os

'''
An exception is an event that occurs during the execution of a program and disrupts the normal flow of the program's instructions.
An exception is a Python object that represents an error.
When a Python script raises an exception it must handle the exception immediately, otherwise it terminates and quits.
'''

# try ... except ... else
try:
    f = open("test.txt", "w")           # Open file in write mode
    f.write("Writing to file Test\n")   # Write to file
except IOError:
    print("Error opening the file!")
else:
    print("Written content in the file successfully")

f.close()
print()

try:
    f = open("test.txt", "r")           # Open file in read mode
    f.write("Writing to file Test\n")   # Write to file -> error
except IOError:
    print("Error: writing to file in read mode")
else:
    print("Written content in the file successfully")
    
f.close()
print()

# except clause with no exceptions
'''
It catches all the exceptions that occur, but it's not considered a good programming practice
because the exceptions that cause the problem are not identified
'''
try:
    f = open("test.txt", "r")           # Open file in read mode
    f.write("Writing to file Test\n")   # Write to file -> error
except:
    print("Error: writing to file in read mode")
else:
    print("Written content in the file successfully")

f.close()
print()

# except clause with multiple exceptions
try:
    f = open("test.txt", "a")           # Open file in append mode
    f.write("Appending to file Test\n") # Append to file
except (IOError, OSError, SystemError):
    print("Error opening the file!")
else:
    print("Written content in the file successfully")

f.close()
print()

# try ... finally
'''
The finally block executes whether the try-block raised an exception or not.
It's not possible to use except and finally in the same try block.
'''
try:
    f = open("test.txt", "r")               # Open file in read mode
    try:
        f.write("Writing to file Test\n")   # Write to file -> error
    finally:
        print("Closing the file")
        f.close()
        # Delete the file
        os.remove("test.txt")
except IOError:
    print("Error: writing to file in read mode")

print()

# Argument of an exception
def temp_convert(var):
    try:
        return int(var)
    except ValueError as e:
        print("Error:", e)

temp_convert("xyz")
print()

# Raising an exception
def setLevel (level):
    if (level < 1):
        raise Exception(level)
    return level

try:
    l = setLevel(0)
    print("level = ", l)
except Exception as e:
    print("raise Exception(level):")
    print("setLevel argument: ", e.args[0])

print()

# User-defined exceptions
class Networkerror(RuntimeError):
    def __init__(self, arg):
        self.args = arg

try:
    raise Networkerror("Bad hostname")
except Networkerror as e:
    error =  ''.join(e.args)
    print("Error: ", error)

print()

# assert #
def KelvinToFahrenheit (Temperature):
    assert (Temperature >= 0), "Colder than absolute zero!"
    return ((Temperature - 273) * 1.8) + 32

print(KelvinToFahrenheit(273))
print(int(KelvinToFahrenheit(505.78)))
print(KelvinToFahrenheit(-5))
print()