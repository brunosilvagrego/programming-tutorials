#include <stdio.h>

int main ()
{
    int a = 100;

    /* if ... else */
    if (a == 10)
    {
        printf("a = 10\n" );
    }
    else if (a == 20)
    {
      printf("a = 20\n" );
    }
    else if( a == 30 )
    {
        printf("Value of a is 30\n" );
    }
    // If none of the conditions is true
    else
    {
        printf("None of the expected values matches\n" );
    }

    printf("a = %d\n\n", a );

    /* switch */
    char grade = 'B';

    switch (grade)
    {
        case 'A' :
            printf("Excellent!\n" );
            break;
        case 'B' :
        case 'C' :
            printf("Well done\n" );
            break;
        case 'D' :
            printf("You passed\n" );
            break;
        case 'F' :
            printf("Better try again\n" );
            break;
        default :
            printf("Invalid grade\n" );
    }

    printf("Your grade = %c\n\n", grade);

    /* Nested switch */
    int x = 100;
    int y = 200;

    switch (x)
    {
        case 100:
            printf("This is part of outer switch\n");

            switch (y)
            {
                case 200:
                    printf("This is part of inner switch\n");
            }
    }

    return 0;
}
