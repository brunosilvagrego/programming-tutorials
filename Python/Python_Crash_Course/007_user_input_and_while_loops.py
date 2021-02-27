# Writing Clear Prompts
name = input("Please enter your name: ")
print("\nHello, " + name + "!")
print()

prompt = "If you tell us who you are, we can personalize the messages you see."
prompt += "\nWhat is your first name? "
name = input(prompt)
print("\nHello, " + name + "!")
print()

# Using int() to Accept Numerical Input
height = input("How tall are you, in inches? ")
height = int(height)

if height >= 36:
    print("\nYou're tall enough to ride the roller coaster!")
else:
    print("\nYou'll be able to ride the roller coaster when you're a little older.")

print()

# The Modulo Operator
number = input("Enter a number, and I'll tell you if it's even or odd: ")
number = int(number)

if number % 2 == 0:
    print("\nThe number " + str(number) + " is even.")
else:
    print("\nThe number " + str(number) + " is odd.")

print()

# The while Loop in Action
current_number = 1

while current_number <= 5:
    print(current_number)
    current_number += 1

print()

# Letting the User Choose When to Quit
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program. "
message = ""

while message != 'quit':
    message = input(prompt)

    if message != 'quit':
        print(message)

print()

# Using a Flag
prompt = "\nTell me something, and I will repeat it back to you:"
prompt += "\nEnter 'quit' to end the program. "
active = True

while active:
    message = input(prompt)
    
    if message == 'quit':
        active = False
    else:
        print(message)

print()

# Using 'break' to Exit a Loop
# NOTE: The 'break' statement can be used in any of Python’s loops.
# It's possible to use 'break' to quit a for loop that’s working through
# a list or a dictionary.
prompt = "\nPlease enter the name of a city you have visited:"
prompt += "\n(Enter 'quit' when you are finished.) "

while True:
    city = input(prompt)

    if city == 'quit':
        break
    else:
        print("I'd love to go to " + city.title() + "!")

print()

# Using 'continue' in a Loop
user_number = input("Enter a number, please: ")
user_number = int(user_number)

number = 0

while number < user_number:
    number += 1
    
    if number % 2 == 0:
        continue

    print(number)

print()

# Moving Items from One List to Another
unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

while unconfirmed_users:
    current_user = unconfirmed_users.pop()
    print("Verifying user: " + current_user.title())

    confirmed_users.append(current_user)
    print("\nThe following users have been confirmed:")

for confirmed_user in confirmed_users:
    print(confirmed_user.title())

print()

# Removing All Instances of Specific Values from a List
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat']
print(pets)

while 'cat' in pets:
    pets.remove('cat')

print(pets)
print()

# Filling a Dictionary with User Input
responses = {}

# Set a flag to indicate that polling is active.
polling_active = True

while polling_active:
    # Prompt for the person's name and response.
    name = input("\nWhat is your name? ")
    response = input("Which mountain would you like to climb someday? ")

    # Store the response in the dictionary:
    responses[name] = response

    # Find out if anyone else is going to take the poll.
    repeat = input("Would you like to let another person respond? (yes/no) ")
    if repeat == 'no':
        polling_active = False

# Polling is complete. Show the results.
print("\n--- Poll Results ---")

for name, response in responses.items():
    print(name + " would like to climb " + response + ".")

print()
