'''
Tuples are sequences, just like lists. The main difference is that tuples data cannot be changed.
'''

# Tuples #
tup1 = ('physics', 'chemistry', 1997, 2000)
print("tup1 = ", tup1)
print("tup1[0] = ", tup1[0])
print()

tup2 = (1, 2, 3, 4, 5, 6, 7)
print("tup2 = ", tup2)
print("tup2[1:5] = ", tup2[1:5])
print()

# Basic Tuples Operations #
# Length
print("len(tup1) = ", len(tup1))
print("len(tup2) = ", len(tup2))
print()

# Concatenation
tup3 = tup1 + tup2
print("tup3 = ", tup3)
print("len(tup3) = ", len(tup3))
print()

# Repetition
'''
To create a tuple containing a single value you have to include a comma, even though there is only one value
'''
tup4 = ('Hi',) * 5
print("tup4 = ", tup4)
print("len(tup4) = ", len(tup4))
print()

# Membership
print("2000 in tup1 = ", 2000 in tup1)
print()

# Iteration
for x in tup4 : print(x)
print()

# Indexing, Slicing and Matrixes #
T=('C++', 'Java', 'Python')
print("T = ", T)
print("T[2] = ", T[2])      # Offsets start at zero
print("T[-2] = ", T[-2])    # Negative: count from the right
print("T[1:] = ", T[1:])    # Slicing fetches sections
print()

# Built-in Tuple Functions and Methods #
# len()
print("len(tup1) = ", len(tup1))
print("len(tup2) = ", len(tup2))
print("len(tup3) = ", len(tup3))
print("len(tup4) = ", len(tup4))
print("len(T) = ", len(T))
print()

# max()
print("max(tup2) = ", max(tup2))
print("max(T) = ", max(T))
print()

# min()
print("min(tup2) = ", min(tup2))
print("min(T) = ", min(T))
print()

# tuple()
list1 = ['maths', 'che', 'phy', 'bio']
tup5 = tuple(list1)
print("tup5 = ", tup5)
print()