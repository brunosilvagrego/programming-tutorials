#include <stdio.h>

/* Character Literals */
#define NEWLINE '\n'

/* Integer Literals */
#define INT_LITERAL_01  212     // Legal
#define INT_LITERAL_02  215u    // Legal
#define INT_LITERAL_03  0xFeeL  // Legal
#define INT_LITERAL_04  078     // Illegal: 8 is not an octal digit
#define INT_LITERAL_05  032UU   // Illegal: cannot repeat a suffix
#define INT_LITERAL_06  85      // decimal
#define INT_LITERAL_07  0213    // octal
#define INT_LITERAL_08  0x4b    // hexadecimal
#define INT_LITERAL_09  30      // int
#define INT_LITERAL_10  30u     // unsigned int
#define INT_LITERAL_11  30l     // long
#define INT_LITERAL_12  30ul    // unsigned long

/* Floating-Point Literals */
#define FLOAT_LITERAL_01    1.23456     // Legal
#define FLOAT_LITERAL_02    123456E-5L  // Legal
#define FLOAT_LITERAL_03    123456e-5L  // Legal
#define FLOAT_LITERAL_04    510E        // Illegal: incomplete exponent
#define FLOAT_LITERAL_05    210f        // Illegal: no decimal or exponent
#define FLOAT_LITERAL_06    .e55        // Illegal: missing integer or fraction

/* String Literals */
#define STRING_LITERAL_01   "Hello"
#define STRING_LITERAL_02   "World"

// NOTE: It is a good programming practice to define constants in CAPITALS
#define LENGTH  10
#define WIDTH   5
#define PI      3.14159


int main ()
{
    int area;
    float circle_area;

    /* Constants with literal Macros */
    area = LENGTH * WIDTH;
    printf("Rectangle Area = %d\n", area);
    printf("%c", NEWLINE);

    /* Constants with const variables */
    const int BASE = 10;
    const int HEIGHT = 5;
    const char CARRIAGE_RETURN = '\n';

    area = (BASE * HEIGHT) / 2;
    printf("Triangle Area = %d\n", area);
    printf("%c", CARRIAGE_RETURN);

    /* Floating-Point Literals */
    float const radius = 2.5;
    circle_area = PI * radius * radius;
    printf("Circle Area = %f\n", circle_area);
    printf("%c", CARRIAGE_RETURN);

    /* String Literals */
    printf("%s, %s!\n", STRING_LITERAL_01, STRING_LITERAL_02);
    printf("%c", NEWLINE);

    return 0;
}
