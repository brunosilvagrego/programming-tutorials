#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void printArray (int array[], unsigned size)
{
    printf("\n[ ");

    for (unsigned i = 0; i < size; i++)
    {
        if (i == (size-1))
        {
            printf("%d ", array[i]);
        }
        else
        {
            printf("%d, ", array[i]);
        }
    }

    printf("]\n");
}

void swap (int* x, int* y)
{
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

void bubbleSort (int array[], unsigned size)
{
    bool swapped = true;

    // Loop through all numbers
    for (unsigned i = 0; (i < size-1) && (swapped == true); i++)
    {
        swapped = false;

        // Last i elements are already in place
        for(unsigned j = 0; j < size-1-i; j++)
        {
            if(array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);

                swapped = true;
            }
        }

        printf("\nIteration #%d ", (i+1));
        printArray(array, size);
   }
}

int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    unsigned size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    bubbleSort(array, size);

    printf("\nOutput Array: ");
    printArray(array, size);
}
