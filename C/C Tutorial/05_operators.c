#include <stdio.h>

void printBits (size_t const size, void const * const ptr);


int main ()
{
    int a = 21;
    int b = 10;

    /* Arithmetic Operators */
    printf("a = %d\n", a);
    printf("b = %d\n\n", b);

    printf("Arithmetic Operators:\n");
    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);
    printf("a %% b = %d\n", a % b);
    printf("a++ = %d\n", ++a);
    printf("b-- = %d\n", --b);
    printf("\n");

    /* Relational Operators */
    printf("Relational Operators:\n");
    printf("a == b = %d\n", (a == b));
    printf("a != b = %d\n", (a != b));
    printf("a > b  = %d\n", (a > b));
    printf("a < b  = %d\n", (a < b));
    printf("a >= b = %d\n", (a >= b));
    printf("a <= b = %d\n", (a <= b));
    printf("\n");

    /* Logical Operators */
    a = 0;
    printf("a = %d\n\n", a);

    printf("Logical Operators:\n");
    printf("a && b = %d\n", (a && b));
    printf("a || b = %d\n", (a || b));
    printf("!a     = %d\n", (!a));
    printf("!b     = %d\n", (!b));
    printf("\n");

    /* Bitwise Operators */
    char c = 3;
    char d = 5;
    char result = 0;

    printf("c      = ");
    printBits(sizeof(c), &c);

    printf("d      = ");
    printBits(sizeof(d), &d);

    printf("\n");

    printf("Bitwise Operators:\n");

    printf("c & d  = ");
    result = c & d;
    printBits(sizeof(result), &result);

    printf("c | d  = ");
    result = c | d;
    printBits(sizeof(result), &result);

    printf("c ^ d  = ");
    result = c ^ d;
    printBits(sizeof(result), &result);

    printf("~c     = ");
    result = ~c;
    printBits(sizeof(result), &result);

    printf("d >> 2 = ");
    result = d >> 2;
    printBits(sizeof(result), &result);

    printf("c << 2 = ");
    result = c << 2;
    printBits(sizeof(result), &result);

    printf("\n");

    /* Assignment Operators */
    a = 25;
    printf("a = %d\n", a);

    printf("c = ");
    printBits(sizeof(c), &c);
    printf("\n");

    printf("Assignment Operators:\n");
    printf("a += 2  = %d\n", a += 2);
    printf("a -= 2  = %d\n", a -= 2);
    printf("a *= 2  = %d\n", a *= 2);
    printf("a /= 2  = %d\n", a /= 2);
    printf("a %%= 2  = %d\n", a %= 2);

    printf("c &= 1  = ");
    c &= 1;
    printBits(sizeof(c), &c);

    printf("c |= 4  = ");
    c |= 4;
    printBits(sizeof(c), &c);

    printf("c ^= 2  = ");
    c ^= 2;
    printBits(sizeof(c), &c);

    printf("c <<= 2 = ");
    c <<= 2;
    printBits(sizeof(c), &c);

    printf("c >>= 1 = ");
    c >>= 1;
    printBits(sizeof(c), &c);

    printf("\n");

    /* Ternary Operator */
    printf("Ternary Operator:\n");
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("(a < b) ? a : b = %d\n\n", (a < b) ? a : b);
    printf("a = %d\n", a = 10);
    printf("b = %d\n", b);
    printf("(a < b) ? a : b = %d\n", (a < b) ? a : b);
}

// assumes little endian
void printBits (size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;

    for (i = size-1; i >= 0; i--)
    {
        for (j = 7; j >= 0; j--)
        {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }

        printf(" ");
    }

    printf("\n");
}
