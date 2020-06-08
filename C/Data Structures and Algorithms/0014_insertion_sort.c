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

void insertionSort(int array[], int size)
{
    int i, j;
    int key;

    for (i = 1; i < size; i++)
    {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead of their current position
        while ((j >= 0) && (array[j] > key))
        {
            array[j+1] = array[j];
            --j;
        }

        array[j + 1] = key;

        printf("\nIteration #%d ", i);
        printArray(array, size);
    }
}

int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    insertionSort(array, size);

    printf("\nOutput Array: ");
    printArray(array, size);
}
