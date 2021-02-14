# Creating and Using a Class

class Dog():    # class Dog(object): in Python 2.7
    """A simple attempt to model a dog."""

    # The __init__() method at is a special method Python runs automatically
    # whenever a new instance based on the Dog class is created.
    def __init__(self, name, age):
        """Initialize name and age attributes."""
        self.name = name
        self.age = age

    # A function that’s part of a class is a method.
    def sit(self):
        """Simulate a dog sitting in response to a command."""
        print(self.name.title() + " is now sitting.")

    # A function that’s part of a class is a method.
    def roll_over(self):
        """Simulate rolling over in response to a command."""
        print(self.name.title() + " rolled over!")

    # NOTE: Every method call associated with a class automatically passes self,
    # which is a reference to the instance itself. It gives the individual
    # instance access to the attributes and methods in the class.

# Making an Instance from a Class
# NOTE: The __init__() method has no explicit return statement, but Python
# automatically returns an instance representing this dog.
my_dog = Dog('willie', 6)

# Accessing Attributes
print("My dog's name is " + my_dog.name.title() + ".")
print("My dog is " + str(my_dog.age) + " years old.")

# Calling Methods
my_dog.sit()
my_dog.roll_over()
print()

# Creating Multiple Instances
your_dog = Dog('lucy', 3)
print("Your dog's name is " + your_dog.name.title() + ".")
print("Your dog is " + str(your_dog.age) + " years old.")
your_dog.sit()
print()

# Working with Classes and Instances
class Car():
    """A simple attempt to represent a car."""
    def __init__(self, make, model, year):
        """Initialize attributes to describe a car."""
        self.make = make
        self.model = model
        self.year = year
        self.odometer_reading = 0   # Setting a Default Value for an Attribute

    def get_descriptive_name(self):
        """Return a neatly formatted descriptive name."""
        long_name = str(self.year) + ' ' + self.make + ' ' + self.model
        return long_name.title()

    def read_odometer(self):
        """Print a statement showing the car's mileage."""
        print("This car has " + str(self.odometer_reading) + " miles on it.")

    # Modifying an Attribute’s Value Through a Method
    def update_odometer(self, mileage):
        """
        Set the odometer reading to the given value.
        Reject the change if it attempts to roll the odometer back.
        """
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")

    # Incrementing an Attribute’s Value Through a Method
    def increment_odometer(self, miles):
        """Add the given amount to the odometer reading."""
        self.odometer_reading += miles

my_new_car = Car('audi', 'a4', 2016)
print(my_new_car.get_descriptive_name())
my_new_car.read_odometer()
print()

# Modifying an Attribute’s Value Directly
print(my_new_car.get_descriptive_name())
my_new_car.odometer_reading = 23
my_new_car.read_odometer()
print()

# Modifying an Attribute’s Value Through a Method
print(my_new_car.get_descriptive_name())
my_new_car.update_odometer(10)
my_new_car.update_odometer(46)
my_new_car.read_odometer()
print()

# Incrementing an Attribute’s Value Through a Method
my_used_car = Car('subaru', 'outback', 2013)
print(my_used_car.get_descriptive_name())

my_used_car.update_odometer(23500)
my_used_car.read_odometer()

my_used_car.increment_odometer(650)
my_used_car.read_odometer()
print()

# Inheritance
# NOTE: When one class inherits from another, it automatically takes on all
# the attributes and methods of the first class. The original class is called
# the parent class, and the new class is the child class.
class ElectricCar(Car):
    """Represent aspects of a car, specific to electric vehicles."""

    def __init__(self, make, model, year):
        """
        Initialize attributes of the parent class.
        Then initialize attributes specific to an electric car.
        """
        # The name super comes from a convention of calling the parent class
        # a superclass and the child class a subclass.
        super().__init__(make, model, year)
        # super(ElectricCar, self).__init__(make, model, year) in Python 2.7

        self.battery_size = 70

    # Defining a method for the Child Class
    def describe_battery(self):
        """Print a statement describing the battery size."""
        print("This car has a " + str(self.battery_size) + "-kWh battery.")

    # Overriding a method from the Parent Class
    # NOTE: Define a method in the child class with the same name as the method
    # to override in the parent class.
    def read_odometer(self):
        """Print a statement showing the car's odometer reading in km."""
        print("This car has " + str(self.odometer_reading * 1.61) + " km on it.")

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_descriptive_name())
my_tesla.describe_battery()
my_tesla.read_odometer()
my_tesla.increment_odometer(100)
my_tesla.read_odometer()
print()

# Instances as Attributes
class Battery():
    """A simple attempt to model a battery for an electric car."""

    def __init__(self, battery_size=70):
        """Initialize the battery's attributes."""
        self.battery_size = battery_size

    def describe_battery(self):
        """Print a statement describing the battery size."""
        print("This car has a " + str(self.battery_size) + "-kWh battery.")

    def get_range(self):
        """Print a statement about the range this battery provides."""
        if self.battery_size == 70:
            range = 240
        elif self.battery_size == 85:
            range = 270

        message = "This car can go approximately " + str(range)
        message += " miles on a full charge."
        print(message)

class EV(Car):
    """Represent aspects of a car, specific to electric vehicles."""

    def __init__(self, make, model, year):
        """
        Initialize attributes of the parent class.
        Then initialize attributes specific to an electric car.
        """
        super().__init__(make, model, year)
        self.battery = Battery()

my_ev = EV('tesla', 'model 3', 2020)
print(my_ev.get_descriptive_name())
my_ev.battery.battery_size = 85
my_ev.battery.describe_battery()
my_ev.battery.get_range()
print()

# Importing a Single Class
from car import Car

my_new_car = Car('audi', 'a4', 2018)
print(my_new_car.get_descriptive_name())
my_new_car.odometer_reading = 40
my_new_car.read_odometer()
print()

# Storing Multiple Classes in a Module
from car import ElectricCar

my_tesla = ElectricCar('tesla', 'model s', 2016)
print(my_tesla.get_descriptive_name())
my_tesla.battery.describe_battery()
my_tesla.battery.get_range()
print()

# Importing Multiple Classes from a Module
from car import Car, ElectricCar

my_beetle = Car('volkswagen', 'beetle', 2016)
print(my_beetle.get_descriptive_name())
print()

my_tesla = ElectricCar('tesla', 'roadster', 2016)
print(my_tesla.get_descriptive_name())
print()

# Importing an Entire Module
import car

my_beetle = car.Car('volkswagen', 'beetle', 2020)
print(my_beetle.get_descriptive_name())
print()

my_tesla = car.ElectricCar('tesla', 'roadster', 2020)
print(my_tesla.get_descriptive_name())
print()

# Importing All Classes from a Module
# NOTE: This method is not recommended for two reasons. First, it’s helpful
# to be able to read the import statements at the top of a file and get a clear
# sense of which classes a program uses. With this approach it’s unclear which
# classes you’re using from the module.
from car import *

# Importing a Module into a Module
from car import Car
from electric_car import ElectricCar

my_beetle = Car('volkswagen', 'beetle', 2018)
print(my_beetle.get_descriptive_name())
print()

my_tesla = ElectricCar('tesla', 'roadster', 2018)
print(my_tesla.get_descriptive_name())
print()

# The Python Standard Library
# NOTE: It is a set of modules included with every Python installation.
from collections import OrderedDict

favorite_languages = OrderedDict()
favorite_languages['jen'] = 'python'
favorite_languages['sarah'] = 'c'
favorite_languages['edward'] = 'ruby'
favorite_languages['phil'] = 'python'

for name, language in favorite_languages.items():
    print(name.title() + "'s favorite language is " + language.title() + ".")

print()
