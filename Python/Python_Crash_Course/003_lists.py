# List
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles)
print(bicycles[0])
print(bicycles[0].title())
print(bicycles[1])
print(bicycles[2])
print(bicycles[3])
print(bicycles[-1])     # Last element
print()

# Modifying Elements in a List
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
motorcycles[0] = 'ducati'
print(motorcycles)
print()

# Adding Elements to a List
motorcycles = []
motorcycles.append('suzuki')
motorcycles.append('yamaha')
motorcycles.append('honda')
print(motorcycles)
print()

# Inserting Elements into a List
motorcycles = ['honda', 'yamaha', 'suzuki']
motorcycles.insert(0, 'ducati')
print(motorcycles)
motorcycles.insert(2, 'bmw')
print(motorcycles)
print()

# Removing Elements from a List
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
del motorcycles[0]
print(motorcycles)
del motorcycles[1]
print(motorcycles)
print()

# Removing an Item Using the pop() Method
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
popped_motorcycle = motorcycles.pop()
print(motorcycles)
print(popped_motorcycle)
print(motorcycles.pop())
print()

# Popping Items from any Position in a List
motorcycles = ['honda', 'yamaha', 'suzuki']
print(motorcycles)
popped_motorcycle = motorcycles.pop()
print(motorcycles.pop(1))
print()

# Removing an Item by Value
# NOTE: The remove() method deletes only the first occurrence of the value you specify.
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
print(motorcycles)
motorcycles.remove('ducati')
print(motorcycles)
print()

# Sorting a List Permanently with the sort() Method
cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
print(cars)

cars.sort(reverse=True)
print(cars)
print()

# Sorting a List Temporarily with the sorted() Function
cars = ['bmw', 'audi', 'toyota', 'subaru']
print("Original list:")
print(cars)
print("Sorted list:")
print(sorted(cars))
print("Original list again:")
print(cars)
print("Sorted in reverse list:")
print(sorted(cars, reverse=True))
print()

# Printing a List in Reverse Order
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(cars)
cars.reverse()
print(cars)
print()

# Finding the Length of a List
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(len(cars))
cars = []
print(len(cars))
print()

# Numbers list
numbers = [3, 6, 1, 9, 2, 4, 8, 5, 7, 13, 11, 12, 15, 14, 18, 16, 17]
print(numbers)
print(sorted(numbers))
print(sorted(numbers, reverse=True))
numbers.reverse()
print(numbers)
print()
