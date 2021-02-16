import os

### Files ###

# File macros
print(__file__)
print(__doc__)
print(__name__)
print(__package__)
print()

# File directory
current_directory = os.path.dirname(os.path.abspath(__file__))
print(current_directory)
print()

# Reading an Entire File
file_path = current_directory + "/Data_Files/pi_digits.txt"
print(file_path)

with open(file_path) as file_object:
    contents = file_object.read()
    print(contents)

print()

# Reading Line by Line
print(file_path)

with open(file_path) as file_object:
    for line in file_object:
        print(line.rstrip())

print()

# Making a List of Lines from a File
# NOTE: The file object returned by open() is only available inside the 'with'
# block that contains it.
print(file_path)

with open(file_path) as file_object:
    lines = file_object.readlines()

for line in lines:
    print(line.rstrip())

print()

# Working with a File’s Contents
pi_string = ""

for line in lines:
    pi_string += line.strip()

print(pi_string)
print(len(pi_string))
print()

two_pi = 2 * float(pi_string)
print(two_pi)
print()

# Large Files: One Million Digits
file_path = current_directory + "/Data_Files/pi_million_digits.txt"
print(file_path)

with open(file_path) as file_object:
    lines = file_object.readlines()

pi_string = ""

for line in lines:
    pi_string += line.strip()

print(pi_string[:52] + "...")
print(len(pi_string))
print()

# Is Your Birthday Contained in Pi?
birthday = "280493"     # ddmmyy format

if birthday in pi_string:
    print("Your birthday appears in the first million digits of pi!")
else:
    print("Your birthday does not appear in the first million digits of pi.")

print()

for line in lines:
    if birthday in line:
        print("Your birthday appears in this line:")
        print(line)

print()

# NOTE: Python opens the file in read-only mode by default. Open modes:
# 'r'  - read mode
# 'w'  - write mode
# 'a'  - append mode
# 'r+' - read and write mode

# NOTE: The open() function automatically creates the file if it doesn’t already
# exist. If the file does exist, Python will erase the file before returning the
# file object.

# Writing to an Empty File
file_path = current_directory + "/Data_Files/programming.txt"

with open(file_path, 'w') as file_object:
    file_object.write("I love programming.")

# Writing Multiple Lines
file_content = ["My name is Bruno.", "I am Portuguese.",
                "And I enjoy programming in Python"]

with open(file_path, 'w') as file_object:
    for line in file_content:
        file_object.write(line + "\n")

# Appending to a File
with open(file_path, 'a') as file_object:
    file_object.write("I hold a master's degree in Electronics Engineering.\n")
    file_object.write("And I have plans to become a software developer soon.\n")


### Exceptions ###

# NOTE: every time your program depends on something external, such as user
# input, the existence of a file, or the availability of a network connection,
# there is a possibility of an exception being raised.

# Using try-except Blocks
try:
    print(5/0)
except ZeroDivisionError:
    print("You can't divide by zero!")

print()

# The else Block
def division(dividend, divisor):
    """Divides two numbers."""
    try:
        answer = dividend / divisor
    except ZeroDivisionError:
        print("You can't divide by 0!")
    else:
        print(answer)

division(5, 0)
division(5, 2)
print()

# Handling the FileNotFoundError Exception
file_path = "alice.txt"

try:
    with open(file_path) as f_obj:
        contents = f_obj.read()
except FileNotFoundError:
    msg = "Sorry, the file " + file_path + " does not exist."
    print(msg)

print()

# Analyzing Text
def count_words(file_path):
    """Count the approximate number of words in a file."""
    try:
        with open(file_path) as f_obj:
            contents = f_obj.read()
    except FileNotFoundError:
        msg = "Sorry, the file " + file_path + " does not exist."
        print(msg)
    else:
        # Count the approximate number of words in the file.
        words = contents.split()
        num_words = len(words)
        print("The file " + file_path + " has about " + str(num_words) + " words.")

base_path = current_directory + "/Data_Files/"

file_names = [
    base_path + "alice_in_wonderland.txt",
    base_path + "siddhartha.txt",
    base_path + "little_women.txt",
    base_path + "moby_dick.txt"
]

for file_name in file_names:
    count_words(file_name)

print()


### Storing Data ###
import json

# Using json.dump() and json.load()
numbers = [2, 3, 5, 7, 11, 13]

file_path = current_directory + "/Data_Files/numbers.json"

with open(file_path, 'w') as file_object:
    json.dump(numbers, file_object)

with open(file_path) as file_object:
    read_numbers = json.load(file_object)

print(read_numbers)
print()

# Refactoring
# NOTE: Improve the code by breaking it up into a series of functions that
# have specific jobs. Refactoring makes the code cleaner, easier to understand,
# and easier to extend.
file_path = current_directory + "/Data_Files/username.json"

# NOTE: a function should either return the expected value, or it should return
# None. This allows to perform a simple test with the return value of the
# function.
def get_stored_username():
    """Get stored username if available."""
    try:
        with open(file_path) as f_obj:
            username = json.load(f_obj)
    except FileNotFoundError:
        return None
    else:
        return username

def get_new_username():
    """Prompt for a new username."""
    username = input("What is your name? ")

    with open(file_path, 'w') as f_obj:
        json.dump(username, f_obj)

    return username

def greet_user():
    """Greet the user by name."""
    username = get_stored_username()

    if username:
        print("Welcome back, " + username + "!")
    else:
        username = get_new_username()
        print("We'll remember you when you come back, " + username + "!")

greet_user()
print()
