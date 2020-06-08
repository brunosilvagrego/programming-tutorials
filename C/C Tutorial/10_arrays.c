#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Functions declaration */
double getAverage (int a[], int size);
int* getRandom ();


int main ()
{
    int i, j;

    /* Array declaration */
    int n[10];  // n is an array of 10 integers

    // Initialize and print elements of array n[]
    for (i = 0; i < 10; i++)
    {
        n[i] = i * 3;

        printf("n[%d] = %d\n", i, n[i]);
    }

    printf("\n");

    /* Passing an Array as a Function Argument */
    printf("\nAverage value of n[] = %f\n\n", getAverage( n, sizeof(n)/sizeof(n[0]) ) );

    /* Multi-dimensional Array */
    const int rows = 3;
    const int columns = 4;

    // Equivalent to: int a[3][4] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int a[3][4] = {
        {0, 1, 2, 3} ,  //  initializers for row indexed by 0
        {4, 5, 6, 7} ,  //  initializers for row indexed by 1
        {8, 9, 0, 1}  //  initializers for row indexed by 2
    };

    // Print the elements of array a[]
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    // Print array a[] in matrix format
    printf("\na[]: \n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < columns; j++)
        {
            printf("%d ", a[i][j]);
        }

        printf("\n");
    }

    printf("\n");

    /* Return Array From Function */
    int *p = getRandom();

    for (i = 0; i < 10; i++ )
    {
        printf( "*(p + %d) : %d\n", i, *(p + i));
    }

    return 0;
}


/* Functions definition */

// Equivalent to:
//     Pointer: double getAverage (int *a, int size)
// Sized array: double getAverage (int a[10], int size)
double getAverage (int a[], int size)
{
    int i;
    double avg;
    double sum = 0;

    for (i = 0; i < size; ++i)
    {
        sum += a[i];
    }

    avg = sum / size;

    return avg;
}

/* function to generate and return random numbers */
int* getRandom ()
{
    static int a[10];
    int i;

    unsigned current_time = (unsigned) time(NULL);

    printf("current_time = %d\n\n", current_time);

    // Set the seed
    srand(current_time);

    for (i = 0; i < 10; ++i)
    {
        a[i] = rand();
    }

    return a;
}
