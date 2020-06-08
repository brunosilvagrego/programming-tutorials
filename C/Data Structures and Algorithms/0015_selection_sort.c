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

void selectionSort(int array[], int size)
{
    int i, j, min_index;

    // One by one move boundary of unsorted sub-array
    for (i = 0; i < size-1; i++)
    {
        // Find the minimum element in unsorted array
        min_index = i;

        for (j = i+1; j < size; j++)
        {
            if (array[j] < array[min_index])
            {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        swap(&array[min_index], &array[i]);

        printf("\nIteration #%d ", (i+1));
        printArray(array, size);
    }
}

int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    selectionSort(array, size);

    printf("\nOutput Array: ");
    printArray(array, size);
}
