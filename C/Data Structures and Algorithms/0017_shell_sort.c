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

void shellSort (int array[], int size)
{
    int iter = 1;

    // Start with a big gap, then reduce the gap
    for (int gap = size/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // Keep adding one more element until the entire array is gap sorted
        for (int i = gap; i < size; i++)
        {
            // Add array[i] to the elements that have been gap sorted
            // Save array[i] in temp and make a hole at position i
            int temp = array[i];

            // Shift earlier gap-sorted elements up until the correct location for array[i] is found
            int j;

            for (j = i; (j >= gap) && (array[j-gap] > temp); j -= gap)
            {
                array[j] = array[j-gap];
            }

            // Put temp (the original a[i]) in its correct location
            array[j] = temp;

            printf("\nIteration #%d ", iter++);
            printArray(array, size);
        }
    }
}


int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    shellSort(array, size);

    printf("\nOutput Array: ");
    printArray(array, size);
}
