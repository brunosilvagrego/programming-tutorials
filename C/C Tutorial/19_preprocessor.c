#include <stdio.h>

/* Macros */
#define message_for(a, b) \
        printf(#a " and " #b ": We love you!\n")

#define tokenpaster(n) printf ("token" #n " = %d", token##n)

#if !defined (MESSAGE)
    #define MESSAGE "You wish!"
#endif

#define SQUARE(x)   ((x) * (x))

#define MAX(x,y)    ((x) > (y) ? (x) : (y))


int main ()
{
    /* Predefined Macros */
    printf("__FILE__ => %s\n", __FILE__ );
    printf("__DATE__ => %s\n", __DATE__ );
    printf("__TIME__ => %s\n", __TIME__ );
    printf("__LINE__ => %d\n", __LINE__ );
    printf("__STDC__ => %d\n", __STDC__ );
    printf("\n");

    /* #define message_for(a, b) */
    message_for(Carole, Debra);
    printf("\n");

    /* #define tokenpaster(n) printf ("token" #n " = %d", token##n) */
    int token34 = 40;
    tokenpaster(34);
    printf("\n\n");

    /* #define MESSAGE */
    printf("Here is the message: %s\n", MESSAGE);
    printf("\n");

    /* #define SQUARE(x) */
    printf("SQUARE(6) = %d\n", SQUARE(6));
    printf("\n");

    /* #define MAX(x,y) */
    printf("MAX(10, 20) = %d\n", MAX(10, 20));
    printf("\n");


    return 0;
}
