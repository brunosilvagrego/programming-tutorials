import os
import csv

from matplotlib import pyplot as plt
from datetime import datetime

def celsius_to_fahrenheit(temperature):
    """Convert Fahrenheit to Celsius."""
    return ((temperature-32) * 5.0/9.0)

# File directory
current_directory = os.path.dirname(os.path.abspath(__file__))

# File path
filename = current_directory + "/../Data_Files/sitka_weather_07-2018_simple.csv"

""" Get high temperatures from file """
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)

    # Printing the Headers and Their Positions
    for index, column_header in enumerate(header_row):
        print(index, column_header)

    # Extracting and Reading Data
    dates = []
    highs = []

    for row in reader:
        current_date = datetime.strptime(row[2], "%Y-%m-%d")
        dates.append(current_date)

        high_temperature = int(celsius_to_fahrenheit(float(row[5])))
        highs.append(high_temperature)

print(highs)

# Plotting Data in a Temperature Chart
fig = plt.figure(dpi=128, figsize=(10, 6))
plt.plot(dates, highs, c='red')

# Formatting
plt.title("Daily high temperatures, July 2018", fontsize=24)
plt.xlabel('', fontsize=16)
fig.autofmt_xdate()
plt.ylabel("Temperature (C)", fontsize=16)
plt.tick_params(axis='both', which='major', labelsize=16)

""" Plotting a Longer Timeframe """
# File path
filename = current_directory + "/../Data_Files/sitka_weather_2018_simple.csv"

# Get high and low temperatures from file
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)

    # Printing the Headers and Their Positions
    for index, column_header in enumerate(header_row):
        print(index, column_header)

    # Extracting and Reading Data
    dates = []
    highs = []
    lows = []

    for row in reader:
        current_date = datetime.strptime(row[2], "%Y-%m-%d")
        dates.append(current_date)

        high_temperature = int(celsius_to_fahrenheit(float(row[5])))
        highs.append(high_temperature)

        low_temperature = int(celsius_to_fahrenheit(float(row[6])))
        lows.append(low_temperature)

# Plotting Data in a Temperature Chart
fig = plt.figure(dpi=128, figsize=(10, 6))
plt.plot(dates, highs, c='red', alpha=0.5)
plt.plot(dates, lows, c='blue', alpha=0.5)

# Shading an area in the chart
plt.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)

# Formatting
plt.title("Daily high and low temperatures, 2018", fontsize=24)
plt.xlabel('', fontsize=16)
fig.autofmt_xdate()
plt.ylabel("Temperature (C)", fontsize=16)
plt.tick_params(axis='both', which='major', labelsize=16)

""" Error-Checking """
# File path
filename = current_directory + "/../Data_Files/death_valley_2018_simple.csv"

# Get high and low temperatures from file
with open(filename) as f:
    reader = csv.reader(f)
    header_row = next(reader)

    # Printing the Headers and Their Positions
    for index, column_header in enumerate(header_row):
        print(index, column_header)

    # Extracting and Reading Data
    dates = []
    highs = []
    lows = []

    # Error checking
    for row in reader:
        try:
            current_date = datetime.strptime(row[2], "%Y-%m-%d")
            high_temperature = int(celsius_to_fahrenheit(float(row[4])))
            low_temperature = int(celsius_to_fahrenheit(float(row[5])))
        except ValueError:
            print(current_date, 'missing data')
        else:
            dates.append(current_date)
            highs.append(high_temperature)
            lows.append(low_temperature)
 
# Plotting Data in a Temperature Chart
fig = plt.figure(dpi=128, figsize=(10, 6))
plt.plot(dates, highs, c='red', alpha=0.5)
plt.plot(dates, lows, c='blue', alpha=0.5)

# Shading an area in the chart
plt.fill_between(dates, highs, lows, facecolor='blue', alpha=0.1)

# Formatting
title = "Daily high and low temperatures - 2018\nDeath Valley, CA"
plt.title(title, fontsize=20)
plt.xlabel('', fontsize=16)
fig.autofmt_xdate()
plt.ylabel("Temperature (C)", fontsize=16)
plt.tick_params(axis='both', which='major', labelsize=16)

""" Display all figures """
plt.show()
