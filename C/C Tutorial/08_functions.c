#include <stdio.h>

/* Functions declaration */
int max(int num1, int num2);

void swap(int *x, int *y);


int main ()
{
    // Local variables definition
    int a = 100;
    int b = 200;

    // Call max() by value
    printf( "Maximum value between %d and %d is: %d\n\n", a, b, max(a, b));

    printf("Before swap(), a = %d\n", a );
    printf("Before swap(), b = %d\n\n", b );

    // Call swap() by reference
    swap(&a, &b);

    printf("After swap(), a = %d\n", a );
    printf("After swap(), b = %d\n", b );

    return 0;
}


/* Functions Definition */
// Function returning the maximum value between two numbers
int max (int num1, int num2)
{
    // Local variable declaration
    int result;

    if (num1 > num2)
    {
        result = num1;
    }
    else
    {
        result = num2;
    }

    return result;
}

// Function to swap the values
void swap (int *x, int *y)
{
    int temp;

    temp = *x;  // Save the value at address x
    *x = *y;    // Copy y value to address x
    *y = temp;  // Copy x value to address y
}
