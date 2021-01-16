import os
import time

# Output
'''
The simplest way to produce output is to use the print() statement which takes zero or more expressions
separated by commas.
'''
print("In ", 2020, ", Python is really a great language,", "isn't it?")
print()

# Input
'''
input() functions read data from keyboard as a string, irrespective of whether it is enclosed with quotes
('' or "" ) or not.
'''
x = input("Type something: ")
print("Your input: ", x)
print()

# Open a file
f = open("test.txt", "wb")
print("f.name = ", f.name)
print("f.closed = ", f.closed)
print("f.mode = ", f.mode)
print()

# Close opened file
f.close()

# Writing to a file
f = open("test.txt", "w")
f.write("Python is a great programming language\nto learn in 2020,\nisn't it?")
f.close()

time.sleep(2)

# Reading a file
f = open("test.txt", "r+")
print("test.txt:")
print(f.read())
print()
f.close()

'''
fileObject.read([count]) -> optional parameter 'count' is the number of bytes to be read from the opened file
'''
# File positions
f = open("test.txt", "r+")
print("First 10 bytes in test.txt:")
print(f.read(10))
print()
print("Current file position: ", f.tell())  # Check current position
f.seek(0, 0)                                # Reposition pointer at the beginning once again
print("First 20 bytes in test.txt:")
print(f.read(20))
print()
f.close()

# Rename a file
os.rename("test.txt", "foo.txt")

# Delete a file
os.remove("foo.txt")

# Display the current directory
print(os.getcwd())

# Create a directory
os.mkdir("Test")

time.sleep(2)

# Remove a directory
os.rmdir('Test')