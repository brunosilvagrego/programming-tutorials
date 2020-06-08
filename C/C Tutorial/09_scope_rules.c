#include <stdio.h>

/* Function declaration */
int sum(int a, int b);

/* Global variable declaration */
int a = 20;


// NOTE: A program can have same name for local and global variables but the value of local variable
//       inside a function will take preference.
//
//       It is a good programming practice to initialize local variables properly, otherwise your program
//       may produce unexpected results, because uninitialized variables will take some garbage value
//       already available at their memory location.

int main ()
{
    /* local variable declaration in main function */
    int a = 10;
    int b = 20;
    int c = 0;

    printf ("value of a in main() = %d\n",  a);
    c = sum(a, b);
    printf ("value of c in main() = %d\n",  c);

    return 0;
}

// NOTE: Formal parameters, are treated as local variables with-in a function and they take precedence
//       over global variables

/* function to add two integers */
int sum(int a, int b)
{
    printf ("value of a in sum() = %d\n",  a);
    printf ("value of b in sum() = %d\n",  b);

    return (a + b);
}
