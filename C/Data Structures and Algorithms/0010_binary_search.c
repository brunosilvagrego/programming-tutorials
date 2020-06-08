#include <stdio.h>

// NOTE: Binary search algorithm only works for sorted arrays

int BinarySearch (int arr[], int size, int val)
{
    int ret = -1;

    int first = 0;
    int last = size - 1;
    int middle = (first+last) / 2;

    while (first <= last)
    {
        if (arr[middle] < val)
        {
            first = middle + 1;
        }
        else if (arr[middle] > val)
        {
            last = middle - 1;
        }
        else if (arr[middle] == val)
        {
            ret = middle;
            break;
        }

        middle = (first + last) / 2;
    }

    return ret;
}


int main(void)
{
	int arr[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
	int size = sizeof(arr) / sizeof(arr[0]);
	int val;
	int result;

	printf("Array: [ ");

	for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("]\n");

    val = 14;
    result = BinarySearch(arr, size, val);

	if (result == -1)
    {
        printf("\nElement '%d' is not present in the array\n", val);
    }
    else
    {
        printf("\nElement '%d' is present at index %d\n", val, result);
    }

    val = 13;
    result = BinarySearch(arr, size, val);

	if (result == -1)
    {
        printf("\nElement '%d' is not present in the array\n", val);
    }
    else
    {
        printf("\nElement '%d' is present at index %d\n", val, result);
    }

	return 0;
}
