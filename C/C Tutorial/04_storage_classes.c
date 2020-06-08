#include <stdio.h>

/* Storage Classes */
// auto     - Default storage class for all local variables.
//
// register - It is used to define local variables that should be stored in a register instead of RAM.
//            It can't have the unary '&' operator applied to it (as it does not have a memory location).
//            Defining 'register' does not mean that the variable will be stored in a register. It means that
//            it MIGHT be stored in a register depending on hardware and implementation restrictions.
//
// static   - It instructs the compiler to keep a local variable in existence during the life-time of the program,
//            instead of creating and destroying it each time it comes into and goes out of scope.
//            When 'static' is used on a global variable, it causes only one copy of that member to be shared by all
//            the objects of its class.
//
// extern   - It is used to give a reference of a global variable that is visible to ALL the program files.
//            It is usually used to declare a global variable or function in another file.

/* Function Declaration */
void func(void);

// Global Variable
static int count = 5;


int main ()
{
    while(count--)
    {
        func();
    }

    return 0;
}


/* Function Definition */
void func ()
{
    // Local static variable
    static int i = 5;

    i++;

    printf("i = %2d | count = %d\n", i, count);
}
