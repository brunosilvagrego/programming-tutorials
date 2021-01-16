# Arithmetic Operators
a = 7
b = 5

print("a = ", a)
print("b = ", b)
print("a + b = ", a + b)    # Addition
print("a - b = ", a - b)    # Subtratcion
print("a * b = ", a * b)    # Multiplication
print("a / b = ", a / b)    # Division
print("a % b = ", a % b)    # Modulus
print("a ** b = ", a ** b)  # Exponent
print("a // b = ", a // b)  # Floor Division
print()

# Comparison Operators
if (a == b):    # equal
    print("a is equal to b")
else:
    print("a is not equal to b")

if (a != b):    # not equal
    print("a is not equal to b")
else:
    print("a is equal to b")

if (a < b):     # less than
    print("a is less than b" )
else:
    print("a is greater than or equal to b")

if (a > b):     # greater than
    print("a is greater than b")
else:
    print("a is less than or equal to b")

if (a <= b):    # less than or equal to
    print("a is less than or equal to b")
else:
    print("a is greater than b")

if (a >= b):    # greater than or equal to
    print("a is greater than or equal to b")
else:
    print("a is less than b")

print()

# Assignment Operators
c = a + b
print("c = a + b = ", c)
c += a
print("c += a = ", c)
c *= a
print("c *= a = ", c)
c /= a 
print("c /= a = ", c)
c %= a
print("c %= a = ", c)
c **= a
print("c **= a = ", c)
c //= a
print("c //= a = ", c)
print()

# Bitwise Operators
print("a = ", bin(a))
print("b = ", bin(b))

c = a & b
print("a & b = ", bin(c))
c = a | b
print("a | b = ", bin(c))
c = a ^ b
print("a ^ b = ", bin(c))
c = ~a
print("~a = ", bin(c))
c = a << 2
print("a << 2 = ", bin(c))
c = a >> 2
print("a >> 2 = ", bin(c))
print()

# Logical Operators
c = True
d = False
print("c = ", c)
print("d = ", d)
print("c and d = ", c and d)               # Logical AND
print("c or d = ", c or d)                 # Logical OR
print("not(c and d) = ", not(c and d))     # Logical NOT
print()

# Membership Operators
l = [1, 2, 3, 4, 5]

if (a in l):
    print("a is available in list l")
else:
    print("a is not available in list l")

if (b not in l):
    print("b is not available in list l")
else:
    print("b is available in list l")

print()

# Identity Operators
e = 20
f = 20
print('e = ', e,':', id(e), '| f = ', f, ':', id(f))

if (e is f):
    print("e and f have the same identity")
else:
    print("e and f do not have the same identity")

if (id(e) == id(f)):
    print("e and f have the same identity")
else:
    print("e and f do not have the same identity")

f = 30
print('e = ', e,':', id(e), '| f = ', f, ':', id(f))

if (e is not f):
    print("e and f do not have the same identity")
else:
    print("e and f have the same identity")

print()