# String declaration
str1 = "This is a string."
str2 = 'This is also a string.'
str3 = 'I told my friend, "Python is my favorite language!"'
str4 = "The language 'Python' is named after Monty Python, not the snake."
str5 = "One of Python's strengths is its diverse and supportive community."

print(str1)
print(str2)
print(str3)
print(str4)
print(str5)
print()

# Changing Case in a String
name = "ada lovelace"
print(name.title())
print(name.upper())
print(name.lower())
print()

# Combining or Concatenating Strings
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name
print(full_name)
print("Hello, " + full_name.title() + "!")
print()

# Adding Whitespace to Strings with Tabs or Newlines
print("Python\n")
print("\tPython\n")
print("Languages:\nPython\nC\nJavaScript\n")
print("Languages:\n\tPython\n\tC\n\tJavaScript\n")

# Stripping Whitespace
favorite_language = " Python "
print(favorite_language.rstrip() == " Python")
print(favorite_language.lstrip() == "Python ")
print(favorite_language.strip() == "Python")
print()

print(id(favorite_language))
favorite_language = favorite_language.rstrip()
print(id(favorite_language))
print()
