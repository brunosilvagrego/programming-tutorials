# For loop
magicians = ['alice', 'david', 'carolina']

for magician in magicians:
    print(magician)

print()

# Doing More Work Within a for Loop
for magician in magicians:
    print(magician.title() + ", that was a great trick!")
    print("I can't wait to see your next trick, " + magician.title() + ".\n")

print("Thank you, everyone. That was a great magic show!")
print()

# Using the range() Function
for value in range(1,5):
    print(value)

print()

# Using range() to Make a List of Numbers
numbers = list(range(1,11))
print(numbers)
print()

# Even numbers between 1 and 10
even_numbers = list(range(2,11,2))
print(even_numbers)
print()

# Odd numbers between 1 and 10
odd_numbers = list(range(1,11,2))
print(odd_numbers)
print()

# First 10 square numbers:
squares = []
for n in range(1,11):
    squares.append(n ** 2)

print(squares)
print()

# Simple Statistics with a List of Numbers
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(min(digits))
print(max(digits))
print(sum(digits))
print()

# List Comprehensions
squares = [value**2 for value in range(1,11)]
print(squares)
print()

# Slicing a List
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players)
print(players[0:3])
print(players[1:4])
print(players[:4])
print(players[2:])
print(players[-2:])
print()

# Looping Through a Slice
print("Here are the first three players on my team:")
for player in players[:3]:
    print(player.title())

print()

# Copying a List content
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]

my_foods.append('cannoli')
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)
print("\nMy friend's favorite foods are:")
print(friend_foods)
print()

# Copying a List reference
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods
my_foods.append('cannoli')
friend_foods.append('ice cream')

print("My favorite foods are:")
print(my_foods)
print("\nMy friend's favorite foods are:")
print(friend_foods)
print()

# An immutable list is called a tuple
dimensions = (200, 50)
print(dimensions[0])
print(dimensions[1])
print()

# Looping Through All Values in a Tuple
for dimension in dimensions:
    print(dimension)

print()

# Writing over a Tuple
# It's possible to assign a new value to a variable that holds a tuple
print("Original dimensions:")
for dimension in dimensions:
    print(dimension)

dimensions = (400, 100)
print("\nModified dimensions:")
for dimension in dimensions:
    print(dimension)

print()
