#include <stdio.h>

int InterpolationSearch (int arr[], int size, int val)
{
    int ret = -1;

    int first = 0;
    int last = size - 1;
    int middle = 0;
    int comparisons = 1;

    while ((first <= last) && (val >= arr[first]) && (val <= arr[last]))
    {
        printf("\nComparison %d\n", comparisons);
        printf("first: %d, array[%d] = %d\n", first, first, arr[first]);
        printf("last: %d, array[%d] = %d\n", last, last, arr[last]);

        comparisons++;

        // probe the mid point
        middle = first + ( ( (double) (last - first) / (arr[last] - arr[first]) ) * (val - arr[first]));
        printf("middle = %d\n", middle);

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
    }

    printf("\nTotal comparisons made: %d\n", --comparisons);

    return ret;
}


int main(void)
{
	int arr[] = {0, 12, 23, 34, 45, 56, 67, 78, 89, 99, 122, 233, 344, 455, 566, 677, 788, 899, 1000};
	int size = sizeof(arr) / sizeof(arr[0]);
	int val;
	int result;

	printf("Array: [ ");

	for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("]\n");

    val = 233;
    result = InterpolationSearch(arr, size, val);

	if (result == -1)
    {
        printf("\nElement '%d' is not present in the array\n", val);
    }
    else
    {
        printf("\nElement '%d' is present at index %d\n", val, result);
    }

    val = 204;
    result = InterpolationSearch(arr, size, val);

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
