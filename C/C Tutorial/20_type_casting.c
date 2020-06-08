#include <stdio.h>

int main ()
{
    int sum = 17, count = 5;
    double mean;
    int  i = 17;
    char c = 'c';   // ASCII value is 99
    float sum2;

    // NOTE: The cast operator has precedence over division, so the value of sum is first converted to type double
    //       and finally it gets divided by count yielding a double value.
    mean = (double) sum / count;
    printf("mean = %f\n", mean);

    // NOTE: Integer Promotion
    sum = i + c;
    printf("\nsum = %d\n", sum);

    // NOTE: Float Promotion
    sum2 = i + c;
    printf("\nsum2 = %f\n", sum2);


    return 0;
}
