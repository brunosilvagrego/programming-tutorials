import random

'''
Python has six built-in types of sequences, but the most common ones are lists and tuples.
The items in a list do not have to be the same type.
'''

# Lists #
list1 = ["physics", "chemistry", 1997, 2000]
list2 = [1, 2, 3, 4, 5, 6, 7]

print("list1 = ", list1)
print("list1[0] = ", list1[0])
print("list2 = ", list2)
print("list2[1:5] = ", list2[1:5])
print()

# Updating List #
list1[2] = 2001
print("Updated list1 = ", list1)
print()

# Delete List Element #
del list1[2]
print("Updated list1 = ", list1)
print()

# Basic List Operations #
# Length
print("len(list1) = ", len(list1))
print("len(list2) = ", len(list2))
print()

# Concatenation
list3 = list1 + list2
print("list3 = ", list3)
print("len(list3) = ", len(list3))
print()

# Repetition
list4 = list1 * 2
print("list4 = ", list4)
print("len(list4) = ", len(list4))
print()

# Membership
print("2000 in list4 = ", 2000 in list4)
print()

# Iteration
for x in list4 : print(x)
print()

# Indexing, Slicing and Matrixes #
list5 = ['C++', 'Java', 'Python']
print("list5 = ", list5)
print("list5[2] = ", list5[2])      # Offsets start at zero
print("list5[-2] = ", list5[-2])    # Negative: count from the right
print("list5[1:] = ", list5[1:])    # Slicing fetches sections
print()

# Built-in List Functions and Methods #
# len()
print("len(list5) = ", len(list5))
print()

# max()
random.shuffle(list2)
print("list2 = ", list2)
print("max(list2) = ", max(list2))
print("list5 = ", list5)
print("max(list5) = ", max(list5))
print()

# min()
random.shuffle(list2)
print("list2 = ", list2)
print("min(list2) = ", min(list2))
print("list5 = ", list5)
print("min(list5) = ", min(list5))
print()

# list()
tuple1 = ('Python', 'Javascript', 'Java', 'C#', 'C++', 'C', 'Scala', 'Go')
list6 = list(tuple1)
print("list6 = ", list6)
print()

# append()
list6.append('Ruby')
print("list6 = ", list6)
print()

# count()
list6.append('Ruby')
print("list6 = ", list6)
print("list6.count('C') = ", list6.count('C'))
print("list6.count('Ruby') = ", list6.count('Ruby'))
print()

# extend()
list7 = list(range(8,15))
print("list7 = ", list7)
list7.extend(list2)
print("list7.extend(list2) = ", list7)
print()

# index()
print("list7.index(7) = ", list7.index(7))
print()

# insert()
list7.insert(9, 15)
print("list7.insert(5, 12) = ", list7)
print()

# pop()
list7.pop()
print("list7.pop() = ", list7)
list7.pop(5)
print("list7.pop(5) = ", list7)
print()

# remove()
list7.remove(15)
print("list7.remove() = ", list7)
list7.remove(14)
print("list7.remove(5) = ", list7)
print()

# reverse()
list6.reverse()
print("list6.reverse() = ", list6)
list7.reverse()
print("list7.reverse() = ", list7)
print()

# sort()
list6.sort()
print("list6.sort() = ", list6)
print()

list8 = list(range(0,21))
print("list8                 = ", list8)
random.shuffle(list8)
print("random.shuffle(list8) = ", list8)
list8.sort()
print("list8.sort()          = ", list8)
print()