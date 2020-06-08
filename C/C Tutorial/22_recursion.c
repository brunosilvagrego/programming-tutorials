#include <stdio.h>

/* Functions declaration */
unsigned long long int factorial (unsigned long long int i);
int fibonacci (int i);


int  main ()
{
    int i;

    for (i = 0; i <= 20; i++)
    {
        printf("factorial(%d) = %lld\n", i, factorial(i));
    }

    printf("\n");

    for (i = 0; i <= 20; i++)
    {
        printf("fibonacci(%d) = %d\n", i, fibonacci(i));
    }


    return 0;
}


/* Functions definition */

unsigned long long int factorial (unsigned long long int i)
{
    if(i <= 1)
    {
        return 1;
    }

    return i * factorial(i - 1);
}


int fibonacci (int i)
{
    if(i == 0)
    {
        return 0;
    }

    if(i == 1)
    {
        return 1;
    }

    return fibonacci(i-1) + fibonacci(i-2);
}
