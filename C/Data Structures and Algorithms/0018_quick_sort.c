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

// This function takes last element as pivot, places the pivot element at its correct position in sorted
// array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot.
int partition (int array[], int low, int high)
{
    int pivot = array[high];    // Pivot
    int i = (low - 1);          // Index of smaller element

    for (int j = low; j <= high-1; j++)
    {
        // If current element is smaller than the pivot
        if (array[j] < pivot)
        {
            i++;    // increment index of smaller element

            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i+1], &array[high]);

    return (i + 1);
}

// The main function that implements QuickSort
// array[] --> Array to be sorted
// low     --> Starting index
// high    --> Ending index
int iter = 1;

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        printf("\nIteration #%d ", iter++);
        printArray(array, high+1);

        int partitionIndex = partition(array, low, high);

        // Separately sort elements before partition and after partition
        quickSort(array, low, partitionIndex-1);
        quickSort(array, partitionIndex+1, high);
    }
}


int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    quickSort(array, 0, size-1);

    printf("\nOutput Array: ");
    printArray(array, size);
}
