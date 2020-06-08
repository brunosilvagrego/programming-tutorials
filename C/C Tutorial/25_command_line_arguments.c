#include <stdio.h>


// NOTE: argc refers to the number of arguments passed.
//       argv[] is a pointer array which points to each argument passed to the program.
//       argv[0] holds the name of the program itself.
//       argv[1] is a pointer to the first command line argument supplied.
//       argv[n] is the last argument.

int main (int argc, char *argv[])
{
    printf("Program name %s\n\n", argv[0]);

    if (argc == 2)
    {
        printf("The argument supplied is %s\n", argv[1]);
    }
    else if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
    }
    else
    {
        printf("One argument expected.\n");
    }

    return 0;
}
