#include <stdio.h>

int main ()
{
    int c;
    char str[100];

    /* gets() */
    printf( "Enter a string: ");
    gets(str);

    /* puts() */
    printf( "You entered: ");
    puts(str);
    putchar('\n');

    /* getchar() */
    printf("Enter a char: ");
    c = getchar();

    /* putchar() */
    printf("You entered: ");
    putchar(c);
    putchar('\n');

    /* scanf() */
    printf("\nEnter an integer: ");
    scanf("%d", &c);

    /* printf() */
    printf("You entered: %d", c);
    putchar('\n');

    /* scanf() */
    printf("\nEnter a string: ");
    scanf("%s", str);

    /* printf() */
    printf("You entered: %s", str);
    putchar('\n');

    return 0;
}
