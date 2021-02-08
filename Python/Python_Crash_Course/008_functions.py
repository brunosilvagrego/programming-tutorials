# Defining a Function
def greet_user():
    """Display a simple greeting."""
    print("Hello!")

greet_user()
print()

# Passing Information to a Function
# NOTE: An argument is a piece of information that is passed from a function
# call to a function. In this functions the value is stored in the parameter
# username .
def greet_personalized(username):
    """Display a simple greeting."""
    print("Hello, " + username.title() + "!")

greet_personalized('jesse')
greet_personalized('sarah')
print()

# Positional Arguments
# NOTE: Python must match each argument in the function call with a parameter
# in the function definition.
def describe_pet(animal_type, pet_name):
    """Display information about a pet."""
    print("I have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('hamster', 'harry')
describe_pet('dog', 'willie')
print()

# Keyword Arguments
describe_pet(animal_type='hamster', pet_name='harry')
describe_pet(pet_name='harry', animal_type='hamster')
describe_pet('hamster', pet_name='harry')

# describe_pet(pet_name='harry', 'hamster')
# SyntaxError: positional argument follows keyword argument

print()

# Default Values
# NOTE: pet_name is a positional argument, therefore it needs to be the first
# argument.
def describe_animal(pet_name, animal_type='dog'):
    """Display information about a pet."""
    print("I have a " + animal_type + ".")
    print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_animal('willie')
describe_animal(pet_name='willie')
describe_animal('harry', 'hamster')
describe_animal(pet_name='harry', animal_type='hamster')
describe_animal(animal_type='hamster', pet_name='harry')
print()

# Returning a Simple Value
def get_formatted_name(first_name, last_name):
    """Return a full name, neatly formatted."""
    full_name = first_name + ' ' + last_name
    return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)
print()

# Making an Argument Optional
def get_formatted_full_name(first_name, last_name, middle_name=''):
    """Return a full name, neatly formatted."""
    if middle_name:
        full_name = first_name + ' ' + middle_name + ' ' + last_name
    else:
        full_name = first_name + ' ' + last_name

    return full_name.title()

musician = get_formatted_full_name('jimi', 'hendrix')
print(musician)
musician = get_formatted_full_name('john', 'hooker', 'lee')
print(musician)
print()

# Returning a Dictionary
def build_person(first_name, last_name, age=''):
    """Return a dictionary of information about a person."""
    person = {'first': first_name, 'last': last_name}

    if age:
        person['age'] = age

    return person

musician = build_person('jimi', 'hendrix', age=27)
print(musician)
print()

# Using a Function with a while Loop
while True:
    print("\nPlease tell me your name:")
    print("(enter 'q' at any time to quit)")

    f_name = input("First name: ")

    if f_name == 'q':
        break

    l_name = input("Last name: ")

    if l_name == 'q':
        break

    formatted_name = get_formatted_name(f_name, l_name)
    print("\nHello, " + formatted_name + "!")

print()

# Passing a List
def greet_users(names):
    """Print a simple greeting to each user in the list."""
    for name in names:
        msg = "Hello, " + name.title() + "!"
        print(msg)

usernames = ['hannah', 'ty', 'margot']
greet_users(usernames)
print()

# Modifying a List in a Function
# NOTE: Any changes made to the list inside the function’s body are permanent.
def print_models(unprinted_designs, completed_models):
    """
    Simulate printing each design, until none are left.
    Move each design to completed_models after printing.
    """
    while unprinted_designs:
        current_design = unprinted_designs.pop()

        # Simulate creating a 3D print from the design.
        print("Printing model: " + current_design)
        completed_models.append(current_design)

def show_completed_models(completed_models):
    """Show all the models that were printed."""
    print("\nThe following models have been printed:")

    for completed_model in completed_models:
        print(completed_model)

unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []
print(unprinted_designs)
print(completed_models)
print()

print_models(unprinted_designs, completed_models)
show_completed_models(completed_models)
print()

print(unprinted_designs)
print(completed_models)
print()

# Preventing a Function from Modifying a List
# by passing the function a copy of the list, not the original.
unprinted_designs = ['iphone case', 'robot pendant', 'dodecahedron']
completed_models = []
print(unprinted_designs)
print(completed_models)
print()

print_models(unprinted_designs[:], completed_models)
print()

print(unprinted_designs)
print(completed_models)
print()

# Passing an Arbitrary Number of Arguments
# NOTE: The asterisk in the parameter name *toppings tells Python to make an
# empty tuple called toppings and pack whatever values it receives into this
# tuple.
def print_ingredients(*toppings):
    """Print the list of toppings that have been requested."""
    print(toppings)

print_ingredients('pepperoni')
print_ingredients('mushrooms', 'green peppers', 'extra cheese')
print()

def make_pizza(*toppings):
    """Summarize the pizza we are about to make."""
    print("\nMaking a pizza with the following toppings:")
    for topping in toppings:
        print("- " + topping)

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
print()

# Mixing Positional and Arbitrary Arguments
def make_sized_pizza(size, *toppings):
    """Summarize the pizza we are about to make."""
    print("\nMaking a " + str(size) +
    "-inch pizza with the following toppings:")

    for topping in toppings:
        print("- " + topping)

make_sized_pizza(16, 'pepperoni')
make_sized_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
print()

# Using Arbitrary Keyword Arguments
# NOTE: The double asterisks before the parameter **user_info cause Python to
# create an empty dictionary called user_info and pack whatever name-value pairs
# it receives into this dictionary.
def build_profile(first, last, **user_info):
    """Build a dictionary containing everything we know about a user."""
    profile = {}
    profile['first_name'] = first
    profile['last_name'] = last

    for key, value in user_info.items():
        profile[key] = value

    return profile

user_profile = build_profile('albert', 'einstein', location='princeton',
                             field='physics')

print(user_profile)
print()

# Importing an Entire Module
import pizza

pizza.make_pizza(16, 'pepperoni')
pizza.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# Importing Specific Functions
from pizza import make_pizza

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# Using as to Give a Function an Alias
from pizza import make_pizza as mp

mp(16, 'pepperoni')
mp(12, 'mushrooms', 'green peppers', 'extra cheese')

# Using as to Give a Module an Alias
import pizza as p

p.make_pizza(16, 'pepperoni')
p.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

# Importing All Functions in a Module
# NOTE: If the module has a function name that matches an existing name in the
# project, it can produce unexpected results. Python may see several functions
# or variables with the same name, and instead of importing all the functions
# separately, it will overwrite the functions.
from pizza import *

make_pizza(16, 'pepperoni')
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')
