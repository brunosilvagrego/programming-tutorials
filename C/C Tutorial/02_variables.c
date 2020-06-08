#include <stdio.h>

/* Variables declaration */
extern int a, b;
extern int c;
extern float f;

int main ()
{
    /* Variables definition */
    int a, b;
    int c;
    float f;

    /* Variables initialization */
    a = 10;
    b = 20;

    c = a + b;
    printf("c = %d \n", c);

    f = 70.0/3.0;
    printf("f = %f \n", f);

    return 0;
}
