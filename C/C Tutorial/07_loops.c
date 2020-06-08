#include <stdio.h>

int main ()
{
    int i = 0;

    /* while loop */
    while (i < 10)
    {
        printf("i = %d\n", i);
        i++;
    }

    printf("\n");

    /* do while loop */
    do
    {
        printf("i = %d\n", i);
        i--;
    }
    while (i > 0);

    printf("\n");

    /* for loop */
    printf("Alphabet:\n");

    for (char c = 'A'; c <= 'z'; ++c)
    {
        printf("%c ", c);
    }

    printf("\n\n");

    /* nested loops */
    int j;

    printf("Prime Numbers:\n");

    for(i = 2; i < 100; i++)
    {
        for(j = 2; j <= (i/j); j++)
        {
            if(!(i%j)) // if factor found, not prime
            {
                // Terminate the inner loop using break statement
                break;
            }
        }

        if(j > (i/j))
        {
            printf("%d ", i);
        }
    }

    printf("\n\n");

    /* continue statement */
    i = 0;

    while (i < 10)
    {
        if(i == 5)
        {
            // Skip the iteration
            printf("\n");
            ++i;
            continue;
        }

        printf("i = %d\n", i);
        ++i;
    }

    printf("\n");


    /* goto statement */
    i = 20;

LOOP:
    while (i > 10)
    {
        if(i == 15)
        {
            // Skip the iteration
            printf("\n");
            --i;
            goto LOOP;
        }

        printf("i = %d\n", i);
        --i;

    }

    printf("\n");

    return 0;
}
