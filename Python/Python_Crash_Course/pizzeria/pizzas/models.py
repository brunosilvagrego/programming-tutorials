from django.db import models

class Pizza(models.Model):
    """A topic the user is learning about"""
    name = models.CharField(max_length=100)

    def __str__(self):
        """Return a string representation of the model."""
        return self.name

class Topping(models.Model):
    """Something specific learned about a topic"""
    pizza = models.ForeignKey(Pizza, on_delete=models.CASCADE)
    name = models.CharField(max_length=100)

    def __str__(self):
        """Return a string representation of the model."""
        return self.name
