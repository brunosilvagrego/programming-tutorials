# Lines and Indentation
if True:
   print("Answer:")
   print("True")

else:
   print("Answer:")
   print("False")

print()

# Multi-Line Statements
total = 5 + \
        4 + \
        3

print(total)
print()

# Quotation
word = 'word'
sentence = "This is a sentence."
paragraph = """This is a paragraph. It is
made up of multiple lines and sentences."""

print(word)
print(sentence)
print(paragraph)
print()

'''
This is a multiline
comment.
'''

# Multiple Statements on a Single Line
import sys; x = 'foo'; sys.stdout.write(x + '\n')
print()

# Multiple Statement Groups as Suites
a = 2

if (a == 1):
   print(a+1)
elif (a == 2): 
   print(a+2) 
else:
   print("unknow 'a'")

# Waiting for the User
input("\n\nPress the enter key to exit.")