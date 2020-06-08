/**** Chapter 4 - Functions and Program Structure ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>

/** Functions prototypes **/
void PrintVector (int v[], int vectorLength);
double AsciiToFloat (char str[]);
void PrintDecimal (int n);
void QuickSort (int v[], int left, int right);
void swap (int v[], int i, int j);

int main()
{
    /**** ASCII to float function test ****/
    char num1[] = "10";
    char num2[] = "-10.789";
    double number1, number2;

    printf("\nNumber strings: %s and %s\n", num1, num2);

    number1 = AsciiToFloat(num1);
    number2 = AsciiToFloat(num2);

    printf("Numbers multiplication: %f\n", number1 * number2);

    /**** Print decimal function test ****/
    int number3 = -5234;
    int number4 = 1009;

    printf("\nDecimal numbers: ");
    PrintDecimal(number3);
    printf(" and ");
    PrintDecimal(number4);
    putchar('\n');

    /**** Quick sort functions test ****/
    int v[20] = {10, -50, 0, -4, 5, -9, 33, 45, -77, 65, -1, 43, -10, 14, -15, 16, -17, 18, -19, 20};
    int vLength = 20;
    int left = 0;
    int right = 19;

    printf("\nv: ");
    PrintVector(v, vLength);
    putchar('\n');

    QuickSort(v, left, right);

    printf("v sorted: ");
    PrintVector(v, vLength);
    putchar('\n');

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

double AsciiToFloat (char str[])
{
    double val, power;
    int i, sign;

    for (i = 0; str[i] == ' '; i++);    /* Skip white space */

    sign = (str[i] == '-') ? -1 : 1;

    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }

    for (val = 0.0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        val = 10.0 * val + (str[i] - '0');
    }

    if (str[i] == '.')
    {
        i++;
    }

    for (power = 1.0; str[i] >= '0' && str[i] <= '9'; i++)
    {
        val = 10.0 * val + (str[i] - '0');
        power *= 10;
    }

    return (sign * val / power);
}

void PrintDecimal (int n)
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }

    if (n / 10)
    {
        PrintDecimal(n/10);
    }

    putchar(n % 10 + '0');
}

void QuickSort (int v[], int left, int right)
{
    int i, last;

    if (left >= right)  /* Do nothing if array contains fewer than two elements */
    {
        return;
    }

    swap(v, left, (left + right) / 2);  /* Move partition element to v[0] partition */
    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if (v[i] < v[left])
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);    /* Restore partition element */

    QuickSort(v, left, last - 1);
    QuickSort(v, last + 1, right);
}

void swap (int v[], int i, int j)
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
