import matplotlib.pyplot as plt
import numpy as np

""" Plotting and Styling Individual Points with scatter() """
# Figure 1
plt.figure(1)

# s argument sets the size of the dots
plt.scatter(2, 4, s=200)

# Style chart
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)
plt.tick_params(axis='both', which='major', labelsize=14)

""" Plotting a Series of Points with scatter() """
# Figure 2
plt.figure(2)

x_values = [1, 2, 3, 4, 5]
y_values = [1, 4, 9, 16, 25]
plt.scatter(x_values, y_values, s=100)

# Style chart
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)
plt.tick_params(axis='both', which='major', labelsize=14)

""" Calculating Data Automatically """
# Figure 3
plt.figure(3)

x_values = list(range(1, 1001))
y_values = [x**2 for x in x_values]     # List comprehension
plt.scatter(x_values, y_values, edgecolor='none', s=10)

# Style chart
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)
plt.tick_params(axis='both', which='major', labelsize=14)
plt.axis([0, 1100, 0, 1100000])

""" Defining Custom Colors using RGB color model """
# Figure 4
plt.figure(4)
plt.scatter(x_values, y_values, c=(0.8, 0, 0), edgecolor='none', s=10)

""" Using a Colormap """
# Figure 5
plt.figure(5)
plt.scatter(x_values, y_values, c=y_values, cmap=plt.cm.Blues, edgecolor='none',
            s=10)

""" Saving Your Plots Automatically """
plt.savefig('squares_plot.png', bbox_inches='tight')

""" Display all figures """
plt.show()
