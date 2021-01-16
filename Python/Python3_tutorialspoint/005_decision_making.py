'''
Python programming language assumes any non-zero and non-null values as TRUE,
and any zero or null values as FALSE.
'''

var = 100

# if
if (var == 100):
    print("var = ", var)

print()

# Single statement suite
if (var < 150): print("var < 150")

print()

# if ... else
amount = int(input("Enter amount: "))

if (amount < 1000):
    discount = amount*0.05
    print("Discount", discount)
else:
    discount = amount*0.10
    print("Discount", discount)
    
print("Net payable:", amount-discount)
print()

# if ... elif ... else
amount = int(input("Enter amount: "))

if (amount < 1000):
    discount = amount*0.05
    print("Discount", discount)
elif (amount < 5000):
    discount = amount*0.10
    print("Discount", discount)
else:
    discount = amount*0.15
    print("Discount", discount)
    
print("Net payable:", amount-discount)
print()

# Nested if statements
num = int(input("Enter a number: "))

if (num % 2 == 0):
    if (num % 3 == 0):
        print("Divisible by 3 and 2")
    else:
        print("Divisible by 2, but not divisible by 3")
else:
    if (num % 3 == 0):
        print("Bivisible by 3, but not divisible by 2")
    else:
        print("Not Divisible by 2 or 3")

print()