#include <stdio.h>

int LinearSearch (int arr[], int size, int val)
{
    int ret = -1;

	for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            ret = i;
        }
    }

	return ret;
}

int main(void)
{
	int arr[] = {2, 0, 1, 4, 3, 6, 5, 8, 7, 10, 9, 12, 11, 14, 13};
	int val = 11;
	int size = sizeof(arr) / sizeof(arr[0]);

	int result = LinearSearch(arr, size, val);

	printf("Array: [ ");

	for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("]\n");

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
