/**** Chapter 1 - A tutorial introduction ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include "MathLib.h"
#include "StringLib.h"

/** Defines **/
#define person "Bruno"
#define IN  0
#define OUT 1

/** Functions prototypes **/
int power(int base, int n);
int GetCharsNum(char str[]);
int GetSpacesNum(char str[]);
int GetWordssNum(char str[]);
void StrCopy (char to[], char from[]);

int main()
{
    /**** First Program in every programming language ****/
    printf("%s says: Hello world!\n", person);

    /**** Fahrenheit to Celsius table ****/
    /* C = (5/9) * (F-32) */
    int fahr_i, celsius_i;
    int lower, upper, step;

    lower = 0;      /* Lower limit of temperature scale */
    upper = 300;    /* Upper limit */
    step = 20;      /* Step size */

    fahr_i = lower;

    printf("\nFahrenheit to Celsius Table\n");

    while (fahr_i<= upper)
    {
        celsius_i = 5 * (fahr_i-32) / 9;
        printf("%d\t%d\n", fahr_i, celsius_i);
        fahr_i = fahr_i + step;
    }

    fahr_i = lower;

    printf("\nFahrenheit to Celsius Formatted Table\n");

    while (fahr_i <= upper)
    {
        celsius_i = 5 * (fahr_i-32) / 9;
        printf("%3d\t%6d\n", fahr_i, celsius_i);
        fahr_i = fahr_i + step;
    }

    /**** Fahrenheit to Celsius float table ****/
    float fahr_f, celsius_f;

    fahr_f = lower;

    printf("\nFahrenheit to Celsius float Table\n");

    while (fahr_f <= upper)
    {
        celsius_f = (5.0/9.0) * (fahr_f-32.0);
        printf("%3.0f\t%6.1f\n", fahr_f, celsius_f);
        fahr_f = fahr_f + step;
    }

    /**** Celsius to Fahrenheit table ****/
    celsius_f = lower;

    printf("\nCelsius to Fahrenheit float Table\n");

    while (celsius_f <= upper)
    {
        fahr_f = (9.0/5.0) * celsius_f + 32.0;
        printf("%3.0f\t%6.1f\n", celsius_f, fahr_f);
        celsius_f = celsius_f + step;
    }

    /**** Celsius to Fahrenheit reverse table ****/
    printf("\nCelsius to Fahrenheit float reverse Table\n");

    for (celsius_f = upper; celsius_f >= 0; celsius_f = celsius_f - step)
    {
        printf("%3.0f\t%6.1f\n", celsius_f, ((9.0/5.0) * celsius_f + 32.0));
    }

    /**** Printing power(m,n) function results ****/
    int i;

    printf("Powers of 2:\n");

    for (i = 0; i < 10; ++i)
    {
        printf("%3d\t%6d\n", i, power(2,i));
    }

    /**** Character, spaces and words counting results ****/
    char c, state, cond;
    cond = 1;
    i = 0;
    int nChars = 0;
    int nSpaces = 0;
    int nWords = 0;

    printf("\nWrite a sentence and press ENTER, please.\n");

    while (i < 50 && cond)
    {
        c = getchar();

        if (c >= ' ' && c <= '~')   /* See ASCII table */
        {
            nChars++;
            i++;
        }

        if (c == ' ')
        {
            nSpaces++;
        }

        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            nWords++;
        }

        if (c == '\n')
        {
            cond = 0;
            nWords++;
        }
    }

    printf("Characters number: %d\n", nChars);
    printf("Spaces number: %d\n", nSpaces);
    printf("Words number: %d\n", nWords);

    /**** Counting characters, spaces and words functions results ****/
    char str[50];
    i = 0;
    cond = 1;

    printf("\nWrite a sentence and press ENTER, please.\n");

    while (i < 50 && cond)
    {
        c = getchar();

        if (c >= ' ' && c <= '~')   /* See ASCII table */
        {
            str[i] = c;
            i++;
        }

        if (c == '\n')
        {
            str[i] = c;
            i++;
            str[i] = 0;
            cond = 0;
        }
    }

    printf("Characters number: %d\n", GetCharsNum(str));
    printf("Spaces number: %d\n", GetSpacesNum(str));
    printf("Words number: %d\n", GetWordssNum(str));

    /**** String copy function print ****/
    char copy[50];

    StrCopy(copy, str);
    printf("\nCopied string: %s\n", copy);

    /**** MathLib.h and StringLib.h test ****/
    printf("\nMathLib_Power(3, 3) = %d\n", MathLib_Power(3, 3));

    char test[] = "I am a test string.";

    printf("\n\"%s\" has %d characters, %d spaces and %d words.\n", test, StringLib_GetCharactersNumber(test),
                                                                            StringLib_GetSpacesNumber(test),
                                                                            StringLib_GetWordsNumber(test));

    char copy2[50];
    StrCopy(copy2, test);
    printf("\nCopied string: %s\n", copy2);

    return 0;
}

int power(int base, int n)
{
    int i, p;

    p = 1;

    for (i = 1; i <= n; i++)
    {
        p = p * base;
    }

    return p;
}

int GetCharsNum(char str[])
{
    int i = 0;
    int count = 0;

    while (str[i] != 0)
    {
        if (str[i] >= ' ' && str[i] <= '~')
        {
            count++;
        }
        i++;
    }

    return count;
}

int GetSpacesNum(char str[])
{
    int i = 0;
    int count = 0;

    while (str[i] != 0)
    {
        if (str[i] == ' ')
        {
            count++;
        }
        i++;
    }

    return count;
}

int GetWordssNum(char str[])
{
    int i = 0;
    int count = 0;
    char state = OUT;

    while (str[i] != 0)
    {
        if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
        {
            state = OUT;
        }
        else if (state == OUT)
        {
            state = IN;
            count++;
        }
        i++;
    }

    return count;
}

void StrCopy (char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != 0)
    {
        i++;
    }
}
