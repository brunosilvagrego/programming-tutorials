/**** Chapter 5 - Pointers and Arrays ****/

/** Includes **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PrintLib.h"

/** Functions prototypes **/
int StringLength (char *s);
void StringCopy (char *s, char *t);
void QuickSortStr (char *v[], int left, int right);
void swap (char *v[], int i, int j);
int DayOfYear (int year, int month, int day);
void MonthDay (int year, int yearday, int *pmonth, int *pday);
char *MonthName (int n);
void QuickSortVoid (void *v[], int left, int right, int (*comp)(void *, void *));
void SwapVoid (void *v[],int i,int j);
void FuncPointerTest (void (*f)(int));
void myPrint (int x);

/* Number of days of each month, array used by functions DayOfYear() and MonthDay() */
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main()
{
    /**** String length function test ****/
    char *str = "Bruno Grego";

    printf("Length of string \"%s\": %d\n", str, StringLength(str));

    /**** Pointers to array test ****/
    int a[4] = {300, 55, 10, 0};
    int *pa;

    pa = &a[0];     /* Equivalent to pa = a */

    printf("\nArray elements: %d, %d, %d, %d\n", *pa, *(pa+1), *(pa+2), *(pa+3));

    /**** String copy function test ****/
    char copy[] = "";

    StringCopy(copy, str);

    printf("\nCopied string: %s\n", copy);

    /**** strcmp function test ****/
    char comp1[] = "abc";
    char comp2[] = "abd";
    char comp3[] = "abe";

    printf("\nstrcmp(%s,%s) = %d\n", comp2, comp1, strcmp(comp2, comp1));
    printf("strcmp(%s,%s) = %d\n", comp2, comp3, strcmp(comp2, comp3));
    printf("strcmp(%s,%s) = %d\n", comp2, comp2, strcmp(comp2, comp2));

    /**** Pointers array example and quick sort strings functions test ****/
    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    printf("\nMonths in numeric order: ");

    int i;
    for (i = 0; i < 12; i++)
    {
        printf("%s%s", months[i], (i < 11) ? ", " : ".\n");
    }

    QuickSortStr(months, 0, 11);

    printf("Months in alphabetic order: ");

    for (i = 0; i < 12; i++)
    {
        printf("%s%s", months[i], (i < 11) ? ", " : ".\n");
    }

    /**** DayOfYear and MonthDay functions test ****/
    int day, month, year, yearday;

    day = 28;
    month = 4;
    year = 1993;

    printf("\n%d/%d/%d is the %d-th day of that year.\n", day, month, year, DayOfYear(year, month, day));

    day = 0;
    month = 0;
    yearday = 118;
    year = 1996;

    MonthDay(year, yearday, &month, &day);

    printf("The %d-th day of the year %d corresponds to the date %d/%d/%d.\n", yearday, year, day, month, year);

    /**** MonthName functions test ****/
    printf("\n");

    for (i = 0; i < 13; i++)
    {
        printf("Month %d is %s and has %d days.\n", i, MonthName(i), daytab[0][i]);
    }

    /**** Pointer to function test ****/
    FuncPointerTest(myPrint);

    return 0;
}

int StringLength (char *s)
{
    int n;

    for (n = 0; *s != 0; s++)
    {
        n++;
    }

    return n;
}

/** String copy, pointer version **/
void StringCopy (char *s, char *t)
{
    /** Array version **/
    /*
    int i = 0;

    while ((s[i] = t[i]) != '\0')
    {
        i++;
    }
    */

    while ((*s = *t) != '\0')
    {
        s++;
        t++;
    }

    /** Equivalent code, increment can be done in postfix **/
    /* while ((*s++ = *t++) != 0); */

    /** Equivalent code, comparison against 0 is redundant **/
    /* while (*s++ = *t++); */
}

void QuickSortStr (char *v[], int left, int right)
{
    int i, last;

    if (left >= right)  /* Do nothing if array contains fewer than two elements */
    {
        return;
    }

    swap(v, left, (left + right)/2);

    last = left;

    for (i = left+1; i <= right; i++)
    {
        if (strcmp(v[i], v[left]) < 0)
        {
            swap(v, ++last, i);
        }
    }

    swap(v, left, last);

    QuickSortStr(v, left, last-1);

    QuickSortStr(v, last+1, right);
}

void swap (char *v[], int i, int j)
{
    char *temp;     /* Since any individual element of v is a character pointer, temp must be also a character pointer */

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/** Return day of year from month and day **/
int DayOfYear (int year, int month, int day)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

/** Return month and day from day of year **/
void MonthDay (int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);

    for (i = 1; yearday > daytab[leap][i]; i++)
    {
        yearday -= daytab[leap][i];
    }

    *pmonth = i;
    *pday = yearday;
}

char *MonthName (int n)
{
    static char *name[] = {"Illegal month", "January", "February", "March", "April", "May", "June", "July", "August", "September",
                           "October", "November", "December"};

    return ((n < 1 || n > 12) ? name[0] : name[n]);
}

void QuickSortVoid (void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    if (left >= right)
    {
        return;
    }

    SwapVoid(v, left, (left + right)/2);

    last = left;

    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(v[i], v[left]) < 0)
        {
            SwapVoid(v, ++last, i);
        }
    }

    SwapVoid(v, left, last);

    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

void SwapVoid (void *v[],int i,int j)
{
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void FuncPointerTest (void (*f)(int))
{
    int i;

    for ( i = 0 ; i < 5 ; i++ )
    {
        (*f)(i);
    }
}

void myPrint (int x)
{
    printf("%d\n", x);
}
