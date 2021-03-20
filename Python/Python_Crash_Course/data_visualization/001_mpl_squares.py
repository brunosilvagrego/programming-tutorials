import matplotlib.pyplot as plt
import numpy as np

""" Plotting a Simple Line Graph """
squares = [1, 4, 9, 16, 25]

# Figure 1
plt.figure(1)
plt.plot(squares)

""" Changing the Label Type and Graph Thickness """
# Figure 2
plt.figure(2)

# Change graph thickness
plt.plot(squares, linewidth=5)

# Set chart title and label axes
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)

# Set size of tick labels
plt.tick_params(axis='both', labelsize=14)

""" Correcting the plot """
x_axis = np.arange(0, 10, 0.1).tolist()
y_axis = [i**2 for i in x_axis]   # List comprehension

# Figure 3
plt.figure(3)
plt.plot(x_axis, y_axis, linewidth=3)
plt.title("Square Numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Square of Value", fontsize=14)
plt.tick_params(axis='both', labelsize=14)

""" Display all figures """
plt.show()
