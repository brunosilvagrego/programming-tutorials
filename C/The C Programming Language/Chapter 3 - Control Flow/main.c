/**** Chapter 3 - Control flow ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** Functions prototypes **/
void PrintVector (int v[], int vectorLength);
int BinarySearch (int x, int v[], int n);
void StringStats (char str[], int stats[]);
int AsciiToInteger (char str[]);
void ShellSort (int v[], int n);
void StringReverse (char str[]);
void IntegerToAscii (int n, char str[]);

int main()
{
    /**** Binary search and shell sort functions test ****/
    int v1[20] = {-10, -9, -8, -7, -6, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int v2[20] = {10, -50, 0, -4, 5, -9, 33, 45, -77, 65, -1, 43, -10, 14, -15, 16, -17, 18, -19, 20};
    int vLength = 20;
    int a = 0;
    int pos = 0;

    printf("v1: ");
    PrintVector(v1, vLength);
    printf("\nv2: ");
    PrintVector(v2, vLength);

    printf("\nType a number, please: \n");
    scanf("%d", &a);

    pos = BinarySearch(a, v1, vLength);

    if (pos == -1)
    {
        printf("Number %d was not found in v1\n", a);
    }
    else
    {
        printf("Number %d was found in position %d of v1\n", a, pos);
    }

    ShellSort(v2, vLength);
    printf("v2 sorted: ");
    PrintVector(v2, vLength);

    /**** String statistics, string reverse and integer to ASCII functions test ****/
    char str[] = "I am small string from 2016";
    int stats[3] = {0, 0, 0};

    StringStats(str, stats);
    printf("\n\nThe sentence \"%s\", has %d spaces, %d digits and %d letters.\n", str, stats[0], stats[1], stats[2]);

    StringReverse(str);
    printf("Reversed string: %s\n", str);

    /**** ASCII to integer function test ****/
    char num1[] = "10";
    char num2[] = "-10";
    int number1, number2;

    printf("\nNumber strings: %s and %s\n", num1, num2);

    number1 = AsciiToInteger(num1);
    number2 = AsciiToInteger(num2);

    printf("Numbers multiplication: %d\n", number1 * number2);

    IntegerToAscii(number1 * number2, num1);
    printf("Numbers multiplication in ASCII form: %s", num1);

    return 0;
}

void PrintVector (int v[], int vectorLength)
{
    int i;

    for (i = 0; i < vectorLength; i++)
    {
        if (i == 0)
        {
            printf("[%d, ", v[i]);
        }
        else if (i == (vectorLength - 1))
        {
            printf("%d]", v[i]);
        }
        else
        {
            printf("%d, ", v[i]);
        }
    }
}

/** Just for sorted arrays **/
int BinarySearch (int x, int v[], int n)
{
    int low, high, mid, i, pos;

    low = 0;
    high = n - 1;
    mid = 0;
    i = 0;
    pos = -1;

    while (low <= high && i < n)
    {
        mid = (low + high) / 2;

        if (x == v[mid])
        {
            pos = mid;
            i = n;
        }
        else if (x < v[mid])
        {
            high = mid + 1;
        }
        else if (x > v[mid])
        {
            low = mid + 1;
        }

        i++;
    }

    return pos;
}

void StringStats (char str[], int stats[])
{
    char c;
    int i, nSpaces, nDigits, nLetters;

    i = nSpaces = nDigits = nLetters = 0;

    while ((c = str[i]) != 0)
    {
        switch (c)
        {
            case '0': case '1': case '2': case '3': case '4':
            case '5': case '6': case '7': case '8': case '9':
                nDigits++;
                break;
            case ' ':
                nSpaces++;
                break;
            default:
                nLetters++;
                break;
        }
        i++;
    }

    stats[0] = nSpaces;
    stats[1] = nDigits;
    stats[2] = nLetters;
}

int AsciiToInteger (char str[])
{
    int i, n, sign;

    for (i = 0; str[i] == ' '; i++);    /* Skip spaces */

    sign = (str[i] == '-') ? -1 : 1;    /* Get sign */

    if (str[i] == '-' || str[i] == '+')     /* Skip sign */
    {
        i++;
    }

    for (n = 0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        n = 10 * n + (str[i] - '0');
    }

    return sign * n;
}

void ShellSort (int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j -= gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
        }
    }
}

void StringReverse (char str[])
{
    int c, i, j;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}

void IntegerToAscii (int n, char str[])
{
    int i, sign;

    if ((sign = n) < 0) /* Record sign */
    {
        n = -n;         /* Make n positive */
    }

    i = 0;

    do                          /* Generate digits in reverse order */
    {
        str[i++] = n % 10 + '0';  /* Get next digit */
    }
    while ((n /= 10) > 0);      /* Delete it */

    if (sign < 0)
    {
        str[i++] = '-';
    }

    str[i] = 0;

    StringReverse(str);
}
