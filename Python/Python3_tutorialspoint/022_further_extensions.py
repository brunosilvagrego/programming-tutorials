'''
File setup.py generates the python lib helloworld from the file hello.c

It's necessary to previously run:
python3 setup.py install

'''

#!/usr/bin/python3
import myModule

print(myModule.fib(10))
print(myModule.version())