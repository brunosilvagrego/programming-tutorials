# while
count = 0

while (count <= 10):
    print(count)
    count = count + 1

print()

# while ... else
count = 5

while (count >= 0):
    print(count)
    count = count - 1
else:
    print("Countdown finished")

print()

# Single statement suite
flag = 1
while (flag): flag = int(input("Enter a number: "))

print()

# for
for var in list(range(5)):
    print(var)

print()

for letter in "Python":     # traversal of a string sequence
    print(letter)

print()

fruits = ["banana", "apple", "mango"]

for fruit in fruits:        # traversal of List sequence
    print(fruit)

print()

for index in range(len(fruits)):
    print(fruits[index])

print()

# for ... else
numbers = [11, 33, 55, 39, 55, 75, 37, 21, 23, 41, 13]

for num in numbers:
    if num%2 == 0:
        print("The list contains an even number")
        break
else:
    print("The list does not contain any even number")

print()

# Nested loops
for i in range(1,11):
    for j in range(1,11):
        k = i*j
        print(k, end=' ')
    print()

print()

# break
for letter in "Python":
    if letter == 'h':
        break
    print(letter)

print()

var = 10
while (var > 0):
    var = var -1
    if var == 5:
        break
    print(var)

print()

# continue
for letter in "Python":
    if letter == 'h':
        continue
    print(letter)

print()

var = 10
while (var > 0):
    var = var -1
    if var == 5:
        continue
    print(var)

print()

'''
The pass statement is a null operation; nothing happens when it executes. The pass statement is also
useful to replace code that has not been written yet (i.e. stubs).
'''
# pass
for letter in 'Python': 
    if letter == 'h':
        pass
    print(letter)

print()

'''
Iterator is an object which allows a programmer to traverse through all the elements of a collection,
regardless of its specific implementation.
'''
# Iterator
list = [1, 2, 3, 4]
it = iter(list)     # Builds an iterator object
print(next(it))     # Prints next available element in iterator

for x in it:
    print(x, end=" ")

print("\n")

'''
A generator is a function that produces or yields a sequence of values using yield method.
'''
# Generator
def fibonacci(n):   # Generator function
    a, b, counter = 0, 1, 0
    while True:
        if (counter > n): 
            return
        yield a
        a, b = b, a + b
        counter += 1

f = fibonacci(10)    # f is iterator object

for x in f:
    print(x, end=" ")

print()