#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *LA;
    LA = malloc(5 * sizeof(int));   // Equivalent to: int LA[5];

    LA[0] = 1;
    LA[1] = 3;
    LA[2] = 5;
    LA[3] = 7;
    LA[4] = 8;

    int item = 10, k = 3, n = 5;
    int i = 0, j = n;

    printf("Original Array:\n");

    /** Traverse **/
    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }


    /** Insertion **/
    LA = realloc(LA, 6 * sizeof(int));

    n = n + 1;

	while (j >= k)
    {
        LA[j+1] = LA[j];
        j = j - 1;
    }

    LA[k] = item;

    printf("\nArray after insertion:\n");

    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }


    /** Deletion **/
    j = k;

    while (j < n)
    {
        LA[j-1] = LA[j];
        j = j + 1;
    }

    n = n-1;
    LA = realloc(LA, 5 * sizeof(int));

    printf("\nArray after deletion:\n");

    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }

    /** Search **/
    j = 0;

    while (j < n)
    {
        if (LA[j] == item)
        {
            break;
        }

        ++j;
    }

    printf("\nFound element %d at position %d\n", item, j+1);


    /** Update **/
    k = 2;
    item = 20;
    LA[k-1] = item;

    printf("\nArray after update:\n");

    for (i = 0; i < n; i++)
    {
        printf("LA[%d] = %d \n", i, LA[i]);
    }

    return 0;
}
