# Checking for Equality
cars = ['audi', 'bmw', 'subaru', 'toyota']

for car in cars:
    if car == 'bmw':
        print(car.upper())
    else:
        print(car.title())

print()

# Ignoring Case When Checking for Equality
# NOTE: A website might use a conditional test like this to ensure that every
# user has a truly unique username, not just a variation on the capitalization
# of another person’s username.
car = 'Audi'

print(car == 'audi')
print(car.lower() == 'audi')
print()

# Checking for Inequality
requested_topping = 'mushrooms'

if requested_topping != 'anchovies':
    print("Hold the anchovies!")

print()

# Numerical Comparisons
age = 23

print(age == 23)
print(age == 24)
print(age < 24)
print(age <= 24)
print(age > 24)
print(age >= 24)
print()

# Using 'and' to Check Multiple Conditions
print(age >= 18 and age <=25)
print(age < 18 and age >25)
print()

# Using 'or' to Check Multiple Conditions
print(age >= 18 or age <=25)
print(age < 18 or age >25)
print()

# Checking Whether a Value Is in a List
requested_toppings = ['mushrooms', 'onions', 'pineapple']

print('mushrooms' in requested_toppings)
print('pepperoni' in requested_toppings)
print()

# Checking Whether a Value Is Not in a List
banned_users = ['andrew', 'carolina', 'david']
users = ['marie', 'andrew', 'bruno', 'carlos', 'david']

for user in users:
    if user not in banned_users:
        print(user.title() + ", you can post a response if you wish.")
    else:
        print(user.title() + ", you're banned!")

print()

# Simple if Statements
age = 19

if age >= 18:
    print("You are old enough to vote!")

print()

# if-else Statements
ages = [17,18]

for age in ages:
    if age >= 18:
        print("You are old enough to vote!")
        print("Have you registered to vote yet?")
    else:
        print("Sorry, you are too young to vote.")
        print("Please register to vote as soon as you turn 18!\n")

print()

# The if-elif-else Chain
ages = [3, 10, 20]

for age in ages:
    if age < 4:
        print("Your admission cost is $0.")
    elif age < 18:
        print("Your admission cost is $5.")
    else:
        print("Your admission cost is $10.")

print()

# Using Multiple elif Blocks
age = 12

if age < 4:
    price = 0
elif age < 18:
    price = 5
elif age < 65:
    price = 10
else:
    price = 5

print("Your admission cost is $" + str(price) + ".")
print()

# Omitting the else Block
age = 25

if age < 4:
    price = 0
elif age < 18:
    price = 5
elif age < 65:
    price = 10
elif age >= 65:
    price = 5

print("Your admission cost is $" + str(price) + ".")
print()

# Testing Multiple Conditions
requested_toppings = ['mushrooms', 'extra cheese']

if 'mushrooms' in requested_toppings:
    print("Adding mushrooms.")
if 'pepperoni' in requested_toppings:
    print("Adding pepperoni.")
if 'extra cheese' in requested_toppings:
    print("Adding extra cheese.")

print("Finished making your pizza!")
print()

# Checking for Special Items
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping == 'green peppers':
        print("Sorry, we are out of green peppers right now.")
    else:
        print("Adding " + requested_topping + ".")

print("Finished making your pizza!")
print()

# Checking That a List Is Not Empty
requested_toppings = []

if requested_toppings:
    for requested_topping in requested_toppings:
        print("Adding " + requested_topping + ".")
        print("\nFinished making your pizza!")
else:
    print("Are you sure you want a plain pizza?")

print()

# Using Multiple Lists
available_toppings = ['mushrooms', 'olives', 'green peppers', 'pepperoni',
                      'pineapple', 'extra cheese']

requested_toppings = ['mushrooms', 'french fries', 'extra cheese']

for requested_topping in requested_toppings:
    if requested_topping in available_toppings:
        print("Adding " + requested_topping + ".")
    else:
        print("Sorry, we don't have " + requested_topping + ".")

print("Finished making your pizza!")
print()
