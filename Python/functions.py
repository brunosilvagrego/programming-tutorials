# Increment list object
def incrementList (listObject):
    i = 0
    while (i < len(listObject)):
        listObject[i] = listObject[i] + 1
        i = i + 1
    
    return

# Function definition
def sumList (listObject):
    total = 0

    for var in listObject:
        total += var

    return total

def diff (arg1, arg2):
   result = arg1 - arg2;    # Local variable
   print("Local variable result  = ", result)
   return result
