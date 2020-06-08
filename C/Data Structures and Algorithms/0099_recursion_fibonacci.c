#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


// Fibonacci Series using Recursion
int fibonacci (int n)
{
    if (n <= 1)
    {
        return n;
    }

    return (fibonacci(n-1) + fibonacci(n-2));
}

// Fibonacci Series using Iteration
void fibonacciIterative (int n)
{
    int f1 = 0;
    int f2 = 1;
    int i;
    int next;

    printf("%d ", f1);

    for (i = 1; i <= n; i++)
    {
        printf("%d ", f2);

        next = f1 + f2;

        f1 = f2;
        f2 = next;
    }
}

int main ()
{
    int n = 20;

    printf("Fibonacci Recursive: ");

    for (int i = 0; i <= n; i++)
    {
        printf("%d ", fibonacci(i));
    }

    printf("\n\nFibonacci Iterative: ");
    fibonacciIterative(n);
    printf("\n");

    return 0;
}
