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

// Merges two sub-arrays of array[].
// First sub-array is array[l ... middle]
// Second sub-array is array[middle+1 ... right]
void merge (int array[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Create temporary arrays
    int leftArray[n1];
    int rightArray[n2];

    // Copy data to leftArray[]
    for (i = 0; i < n1; i++)
    {
        leftArray[i] = array[left+i];
    }

    // Copy data to rightArray[]
    for (j = 0; j < n2; j++)
    {
        rightArray[j] = array[middle+1+j];
    }

    // Merge the temporary arrays back into array[l ... right]
    i = 0;      // Initial index of left sub-array
    j = 0;      // Initial index of right sub-array
    k = left;   // Initial index of merged sub-array

    while (i < n1 && j < n2)
    {
        if (leftArray[i] <= rightArray[j])
        {
            array[k] = leftArray[i];
            i++;
        }
        else
        {
            array[k] = rightArray[j];
            j++;
        }

        k++;
    }

    // Copy the remaining elements of leftArray[], if there  are any
    while (i < n1)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if there are any
    while (j < n2)
    {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int middle = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, middle);
        mergeSort(array, middle+1, right);

        merge(array, left, middle, right);
    }
}


int main()
{
    int array[] = {1, -2, 8, -3, 4, -1, 6, -4, 0, -6, 3, 5, -5, 2, -8, 7, -7, 9, -9, 10, -10};
    int size = sizeof(array) / sizeof(array[0]);

    printf("\nInput Array: ");
    printArray(array, size);

    mergeSort(array, 0, size-1);

    printf("\nOutput Array: ");
    printArray(array, size);
}
