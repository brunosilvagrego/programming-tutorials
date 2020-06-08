#include <iostream>

using namespace std;


// Storage classes:
//      auto     - Default storage class for all local variables.
//
//      register - It defines local variables that should be stored in a register instead of RAM.
//
//      static   - It instructs the compiler to keep a local variable in existence during the life-time of the
//                 program instead of creating and destroying it each time it comes into and goes out of scope.
//
//      extern   - It is used to declare a global variable or function in another file.
//
//      mutable  - It allows a member of an object to override const member function.


/* Function declaration */
void func (void);

/* Global variable */
static int count = 10;

int main()
{
    while (count--)
    {
        func();
    }

    return 0;
}

/* Function definition */
void func (void)
{
    // Local static variable
    static int i = 5;
    i++;

    cout << "i = " << i << "; ";
    cout << "count = " << count << endl;
}
