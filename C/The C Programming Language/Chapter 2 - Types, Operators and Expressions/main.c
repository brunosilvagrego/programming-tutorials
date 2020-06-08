/**** Chapter 2 - Types, operators and expressions ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ConversionLib.h"
#include "StringLib.h"

/** Functions prototypes **/
int StringLength (char str[]);
char IsLeapYear (int year);
int AsciiToInteger (char str[]);
void Squeeze (char str[], char c);
void StringConcatenate (char dest[], char str1[], char str2[]);
void GetString (char str[], int maxLength);
unsigned int GetBits (unsigned int x, int p, int n);
int BitCount (unsigned int x);

#define Max(a, b)   (a > b) ? a : b

/** Global variables **/
enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC};

int main()
{
    /**** String Length, string squeeze and string concatenate functions test ****/
    char str1[50];
    char str2[50];

    printf("Write a sentence with 50 characters or less, please:\n");
    GetString(str1, 50);

    printf("Write another sentence with 50 characters or less, please:\n");
    GetString(str2, 50);

    StringLib_StringSqueezeString(str1, str2);
    printf("First string squeezed by second string: %s\n", str1);

    printf("String 1 length: %d\n", StringLength(str1));
    printf("String 2 length: %d\n", StringLength(str2));

    Squeeze(str1, 'o');
    printf("String 1 \"o\" squeezed: %s\n", str1);

    strcat(str1, str2);

    printf("Strings concatenated: %s\n", str1);
    printf("Strings concatenated length: %d\n", StringLength(str1));

    /**** Enumeration test ****/
    printf("\nMonths:\nJanuary - %d\nFebruary - %d\nMarch - %d\nApril - %d\nMay - %d\nJune - %d\nJuly - %d\nAugust - %d\nSeptember - %d\nOctober - %d\nNovember - %d\nDecember - %d\n", JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC);

    /**** Leap year function test ****/
    int year = 0;

    printf("\nType a year, please: ");
    scanf("%d", &year);

    if (IsLeapYear(year))
    {
        printf("This is not a leap year.\n");
    }
    else
    {
        printf("This is a leap year.\n");
    }

    /**** ASCII to integer function test ****/
    char num[] = "2016";

    printf("\nString number: %s", num);
    printf("\nInteger number: %d\n", AsciiToInteger(num));

    /**** Get bits and bit count functions test ****/
    printf("\nGetBits(0x37,4,3) = %d\n", GetBits(0x37,4,3));
    printf("\nBitCount(0x37) = %d\n", BitCount(0x37));

    /**** Max functions test ****/
    int a = 0;
    int b = 0;

    printf("\nEnter two numbers, please.\n");
    scanf("%d", &a);
    scanf("%d", &b);
    printf("Maximum number is: %d\n", Max(a, b));

    /**** Conversions lib test ****/
    printf("\nConversionsLib_HexadecimalToInteger(\"0x74\") = %d", ConversionsLib_HexadecimalToInteger("0x74"));

    return 0;
}

int StringLength (char str[])
{
    int i = 0;

    while (str[i] != 0)
    {
        i++;
    }

    return i;
}

char IsLeapYear (int year)
{
    char ret;

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        ret = 0;    /* Is leap year */
    }
    else
    {
        ret = 1;    /* Is not */
    }

    return ret;
}

int AsciiToInteger (char str[])
{
    int i = 0;
    int n = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        n = 10 * n + (str[i] - '0');
        i++;
    }

    return n;
}

void Squeeze (char str[], char c)
{
    int i, j;

    for (i = j = 0; str[i] != 0; i++)
    {
        /* Each time a non-c occurs, it is copied into the current j position, an only then j is incremented */
        if (str[i] != c)
        {
            str[j++] = str[i];
        }
    }

    str[j] = 0;
}

void StringConcatenate (char dest[], char str1[], char str2[])
{
    int i, j;

    i = j = 0;

    /* Copy str1 */
    while ((dest[i++] =  str1[j++]) != 0);

    /* Copy str2 */
    j = 0;
    while (str2[j] != 0)
    {
        dest[i] = str2[j];
        i++;
        j++;
    }
}

void GetString (char str[], int maxLength)
{
    char cond = 1;
    char c;
    int i = 0;

    while (i < maxLength && cond)
    {
        c = getchar();

        if (c >= ' ' && c <= '~')   /* See ASCII table */
        {
            str[i] = c;
            i++;
        }

        if (c == '\n')
        {
            str[i] = 0;
            i++;
            cond = 0;
        }
    }

}

/* Get n bits from position p */
unsigned int GetBits (unsigned int x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/* Count 1 bits in x */
int BitCount (unsigned int x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 0x01)
        {
            b++;
        }
    }

    return b;
}
