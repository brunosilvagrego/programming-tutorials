print("support.py imported")

# Hello World
def hello():
    print("Hello World!")
    return

# Fibonacci Series
def fib(n):
    result = []
    a, b = 0, 1

    while (b < n):
        result.append(b)
        a, b = b, a + b
    
    return result

'''
This code will be execute when you run support.py, but it won't be imported when support.py is imported in
another Python file.
'''
if __name__ == "__main__":
    f = fib(50)
    print(f)