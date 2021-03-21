import pygal
from random import randint


class Die():
    """A class representing a single die."""
    def __init__(self, num_sides=6):
        """Assume a six-sided die."""
        self.num_sides = num_sides

    def roll(self):
        """"Return a random value between 1 and number of sides."""
        return randint(1, self.num_sides)


""" Rolling a Die """
# Create a D6
die = Die()

# Make some rolls, and store results in a list
results = []

for roll_num in range(1000):
    result = die.roll()
    results.append(result)

# Analyze the results
frequencies = []

for value in range(1, die.num_sides+1):
    frequency = results.count(value)
    frequencies.append(frequency)

print(frequencies)

""" Making a Histogram """
# Visualize the results
hist = pygal.Bar()

hist.title = "Results of rolling one D6 1000 times"
hist.x_labels = ['1', '2', '3', '4', '5', '6']
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6', frequencies)
hist.render_to_file('die_visual_D6.svg')


def rolling_dice(die_1, die_2, n):
    """Rolling two dices and return the frequencies of the results."""
    # Make some rolls, and store results in a list
    results = []

    for roll_num in range(n):
        result = die_1.roll() + die_2.roll()
        results.append(result)

    # Analyze the results
    frequencies = []
    max_result = die_1.num_sides + die_2.num_sides

    for value in range(2, max_result+1):
        frequency = results.count(value)
        frequencies.append(frequency)

    print(frequencies)

    # Return the frequencies of the results
    return frequencies

""" Rolling Two Dice D6 """
# Create two D6 dice
die_1 = Die()
die_2 = Die()

# Rolling dice
frequencies = rolling_dice(die_1, die_2, 1000)

# Visualize the results
hist = pygal.Bar()

hist.title = "Results of rolling two D6 dice 1000 times."
hist.x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12']
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6 + D6', frequencies)
hist.render_to_file('dice_visual_D6_D6.svg')

""" Rolling Two Dice D8 """
# Create two D8 dice
die_1 = Die(8)
die_2 = Die(8)

# Rolling dice
frequencies = rolling_dice(die_1, die_2, 10000)

# Visualize the results
hist = pygal.Bar()

hist.title = "Results of rolling two D8 dice 10,000 times."
hist.x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13',
                 '14', '15', '16']
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D8 + D8', frequencies)
hist.render_to_file('dice_visual_D8_D8.svg')

""" Rolling Dice of Different Sizes """
# Create a D6 and a D10
die_1 = Die()
die_2 = Die(10)

# Rolling dice
frequencies = rolling_dice(die_1, die_2, 50000)

# Visualize the results
hist = pygal.Bar()

hist.title = "Results of rolling a D6 and a D10 50,000 times."
hist.x_labels = ['2', '3', '4', '5', '6', '7', '8', '9', '10', '11', '12', '13',
                 '14', '15', '16']
hist.x_title = "Result"
hist.y_title = "Frequency of Result"

hist.add('D6 + D10', frequencies)
hist.render_to_file('dice_visual_d6_d10.svg')
