import math
import random

# Number Types #
i = 100         # int
h = 0xA0F       # int - hexadecimal representation
o = 0o37        # int - octal representation
f = 2.54321e2   # float
c = 1 - 2j      # complex number

print("i = ", i)
print("h = ", h)
print("o = ", o)
print("f = ", f)
print("c = ", c)
print()

# Number Type Conversion #
print("int(f) = ", int(f))
print("float(i) = ", float(i))
print("complex(i) = ", complex(i))
print("complex(i,f) = ", complex(i,f))
print()

# Mathematical Functions #
'''
abs() is a built-in function whereas fabs() is defined in math module.
'''
# abs()
print("abs(-45) = ", abs(-45))
print("abs(100.12) = ", abs(100.12))
print("abs(c) = ", abs(c))
print()

'''
fabs() function works only on float and integer whereas abs() works with complex number also.
'''
# fabs()
print("math.fabs(-45.17) = ", math.fabs(-45.17))
print("math.fabs(100.12) = ", math.fabs(100.12))
print("math.fabs(100.72) = ", math.fabs(100.72))
print("math.fabs(math.pi) = ", math.fabs(math.pi))
print()

# ceil()
print("math.ceil(-45.17) = ", math.ceil(-45.17))
print("math.ceil(100.12) = ", math.ceil(100.12))
print("math.ceil(100.72) = ", math.ceil(100.72))
print("math.ceil(math.pi) = ", math.ceil(math.pi))
print()

# floor()
print("math.floor(-45.17) = ", math.floor(-45.17))
print("math.floor(100.12) = ", math.floor(100.12))
print("math.floor(100.72) = ", math.floor(100.72))
print("math.floor(math.pi) = ", math.floor(math.pi))
print()

# round()
print("round(70.23456) = ", round(70.23456))
print("round(56.659,1) = ", round(56.659,1))
print("round(80.264, 2) = ", round(80.264, 2))
print("round(100.000056, 3) = ", round(100.000056, 3))
print("round(-100.000056, 3) = ", round(-100.000056, 3))
print()

# exp()
print("math.exp(-45.17) = ", math.exp(-45.17))
print("math.exp(100.12) = ", math.exp(100.12))
print("math.exp(100.72) = ", math.exp(100.72))
print("math.exp(math.pi) = ", math.exp(math.pi))
print()

# log()
print("math.log(100.12) = ", math.log(100.12))
print("math.log(100.72) = ", math.log(100.72))
print("math.log(math.pi) = ", math.log(math.pi))
print()

# log10()
print("math.log10(100.12) = ", math.log10(100.12))
print("math.log10(100.72) = ", math.log10(100.72))
print("math.log10(119) = ", math.log10(119))
print("math.log10(math.pi) = ", math.log10(math.pi))
print()

# max()
print("max(80, 100, 1000) = ", max(80, 100, 1000))
print("max(-20, 100, 400) = ", max(-20, 100, 400))
print("max(-80, -20, -10) = ", max(-80, -20, -10))
print("max(0, 100, -400) = ", max(0, 100, -400))
print()

# min()
print("min(80, 100, 1000) = ", min(80, 100, 1000))
print("min(-20, 100, 400) = ", min(-20, 100, 400))
print("min(-80, -20, -10) = ", min(-80, -20, -10))
print("min(0, 100, -400) = ", min(0, 100, -400))
print()

# modf()
print("math.modf(100.12) = ", math.modf(100.12))
print("math.modf(100.72) = ", math.modf(100.72))
print("math.modf(119) = ", math.modf(119))
print("math.modf(math.pi) = ", math.modf(math.pi))
print()

# pow()
print("math.pow(100, 2) = ", math.pow(100, 2))
print("math.pow(100, -2) = ", math.pow(100, -2))
print("math.pow(2, 4) = ", math.pow(2, 4))
print("math.pow(3, 0) = ", math.pow(3, 0))
print()

# sqrt()
print("math.sqrt(100) = ", math.sqrt(100))
print("math.sqrt(7) = ", math.sqrt(7))
print("math.sqrt(math.pi) = ", math.sqrt(math.pi))
print()

# Random Number Functions #
# choice()
print("returns a random number from range(100) = ", random.choice(range(100)))
print("returns random element from list [1, 2, 3, 5, 9]) = ", random.choice([1, 2, 3, 5, 9]))
print("returns random character from string 'Hello World' = ", random.choice('Hello World'))
print()

# randrange()
print("randomly select an odd number between 1-100, excluding 2 = ", random.randrange(1, 100, 2))
print("randomly select a number between 0-99 = ", random.randrange(100))
print()

# random()
print("random() = ", random.random())
print("random() = ", random.random())
print()

# seed()
random.seed()
print("random number with default seed = ", random.random())
random.seed(10)
print("random number with int seed = ", random.random())
random.seed("hello", 2)
print("random number with string seed = ", random.random())
print()

# shuffle()
list = [20, 16, 10, 5]
print("original list = ", list)
random.shuffle(list)
print("random.shuffle(list) = ", list)
random.shuffle(list)
print("random.shuffle(list) = ", list)
print()

# uniform()
print("Random Float uniform(5, 10) = ",  random.uniform(5, 10))
print("Random Float uniform(7, 14) = ",  random.uniform(7, 14))
print()

# Trigonometric Functions #
# cos()
print("cos(3) = ",  math.cos(3))
print("cos(-3) = ",  math.cos(-3))
print("cos(0) = ",  math.cos(0))
print("cos(math.pi) = ",  math.cos(math.pi))
print("cos(2*math.pi) = ",  math.cos(2*math.pi))
print()

# sin()
print("sin(3) = ",  math.sin(3))
print("sin(-3) = ",  math.sin(-3))
print("sin(0) = ",  math.sin(0))
print("sin(math.pi) = ",  math.sin(math.pi))
print("sin(math.pi/2) = ",  math.sin(math.pi/2))
print()

# tan()
print("(tan(3) = ",  math.tan(3))
print("tan(-3) = ",  math.tan(-3))
print("tan(0) = ",  math.tan(0))
print("tan(math.pi) = ",  math.tan(math.pi))
print("tan(math.pi/2) = ",  math.tan(math.pi/2))
print("tan(math.pi/4) = ",  math.tan(math.pi/4))
print()

# acos()
print("acos(0.64) = ",  math.acos(0.64))
print("acos(0) = ",  math.acos(0))
print("acos(-1) = ",  math.acos(-1))
print("acos(1) = ",  math.acos(1))
print()

# asin()
print("asin(0.64) = ",  math.asin(0.64))
print("asin(0) = ",  math.asin(0))
print("asin(-1) = ",  math.asin(-1))
print("asin(1) = ",  math.asin(1))
print()

# atan()
print("atan(0.64) = ",  math.atan(0.64))
print("atan(0) = ",  math.atan(0))
print("atan(10) = ",  math.atan(10))
print("atan(-1) = ",  math.atan(-1))
print("atan(1) = ",  math.atan(1))
print()

# atan2()
print("atan2(-0.50,-0.50) = ",  math.atan2(-0.50,-0.50))
print("atan2(0.50,0.50) = ",  math.atan2(0.50,0.50))
print("atan2(5,5) = ",  math.atan2(5,5))
print("atan2(-10,10) = ",  math.atan2(-10,10))
print("atan2(10,20) = ",  math.atan2(10,20))
print()

# degrees()
print("degrees(3) = ",  math.degrees(3))
print("degrees(-3) = ",  math.degrees(-3))
print("degrees(0) = ",  math.degrees(0))
print("degrees(math.pi) = ",  math.degrees(math.pi))
print("degrees(math.pi/2) = ",  math.degrees(math.pi/2))
print("degrees(math.pi/4) = ",  math.degrees(math.pi/4))
print()

# radians
print("radians(3) = ",  math.radians(3))
print("radians(-3) = ",  math.radians(-3))
print("radians(0) = ",  math.radians(0))
print("radians(180) = ",  math.radians(180))
print("radians(90) = ",  math.radians(90))
print("radians(45) = ",  math.radians(45))
print()

# hypot()
print("hypot(3, 2) = ",  math.hypot(3, 2))
print("hypot(-3, 3) = ",  math.hypot(-3, 3))
print("hypot(0, 2) = ",  math.hypot(0, 2))
print()

# Mathematical Constants #
print("pi = ", math.pi)
print("e = ", math.e)
print()