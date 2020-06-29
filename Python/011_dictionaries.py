'''
Each key is separated from its value by a colon (:), the items are separated by commas, and the dictionary
is enclosed in curly braces.

Keys are unique within a dictionary while values may not be. The values of a dictionary can be of any type,
but the keys must be of an immutable data type such as strings, numbers, or tuples.
'''

# Dictionaries #
dict1 = {'Name':'John Smith', 'Age':23, 'Gender':'Male'}
print("dict1 = ", dict1)
print("dict1['Name']: ", dict1['Name'])
print("dict1['Age']: ", dict1['Age'])
print("dict1['Gender']: ", dict1['Gender'])
print()

# Updating Dictionary #
dict1['Age'] = 24;              # Update an existing entry
dict1['University'] = "MIT"     # Add a new entry
print("dict1 = ", dict1)
print()

# Delete Dictionary Elements #
del dict1['Gender']             # Remove entry with key 'Gender'
print("dict1 = ", dict1)
print()

# Built-in Dictionary Functions and Methods #
# len()
print("len(dict1) = ", len(dict1))
print()

# str()
print("str(dict1) = ", str(dict1))
print()

# type()
print("type(dict1) = ", type(dict1))
print()

# copy()
dict2 = dict1.copy()
print("dict2 = ", dict2)
print()

# clear()
dict2.clear()
print("dict2 = ", dict2)
print("len(dict2) = ", len(dict2))
print()

# fromkeys()
tup1 = ('Name', 'Age', 'University')
dict3 = dict.fromkeys(tup1, 'None')
print("dict3 = ", dict3)
print()

# get()
print("dict1.get('Age') = ", dict1.get('Age'))
print("dict1.get('Age', 'NA') = ", dict1.get('Age', 'NA'))
print("dict1.get('Gender') = ", dict1.get('Gender'))
print("dict1.get('Gender', 'NA') = ", dict1.get('Gender', 'NA'))
print()

# items()
print("dict1.items() = ", dict1.items())
print()

# keys()
print("dict1.keys() = ", dict1.keys())
print()

# values()
print("dict1.values() = ", dict1.values())
print()

# setdefault()
dict1.setdefault('Age', 'None')
dict1.setdefault('Gender', 'None')
dict1.setdefault('Nationality', 'Unkown')
print("dict1 = ", dict1)
print()

# update()
dict3.setdefault('Birthday', 'Unkown')
print("dict3 = ", dict3)
dict3.update(dict1)
print("dict3 = ", dict3)
print()