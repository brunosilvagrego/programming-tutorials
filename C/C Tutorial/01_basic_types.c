#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>


int main ()
{
    /* Basic types */
    // char
    // int
    // float
    // double
    // void

    /* Storage sizes */
    printf("Storage sizes:                   Bytes\n");
    printf("sizeof(char)                   : %d \n", sizeof(char));
    printf("sizeof(signed char)            : %d \n", sizeof(signed char));
    printf("sizeof(unsigned char)          : %d \n", sizeof(unsigned char));
    printf("sizeof(short)                  : %d \n", sizeof(short));
    printf("sizeof(short int)              : %d \n", sizeof(short int));
    printf("sizeof(signed short)           : %d \n", sizeof(signed short));
    printf("sizeof(signed short int)       : %d \n", sizeof(signed short int));
    printf("sizeof(unsigned short)         : %d \n", sizeof(unsigned short));
    printf("sizeof(unsigned short int)     : %d \n", sizeof(unsigned short int));
    printf("sizeof(int)                    : %d \n", sizeof(int));
    printf("sizeof(signed)                 : %d \n", sizeof(signed));
    printf("sizeof(signed int)             : %d \n", sizeof(signed int));
    printf("sizeof(unsigned)               : %d \n", sizeof(unsigned));
    printf("sizeof(unsigned int)           : %d \n", sizeof(unsigned int));
    printf("sizeof(long)                   : %d \n", sizeof(long));
    printf("sizeof(long int)               : %d \n", sizeof(long int));
    printf("sizeof(signed long)            : %d \n", sizeof(signed long));
    printf("sizeof(signed long int)        : %d \n", sizeof(signed long int));
    printf("sizeof(unsigned long)          : %d \n", sizeof(unsigned long));
    printf("sizeof(unsigned long int)      : %d \n", sizeof(unsigned long int));
    printf("sizeof(long long)              : %d \n", sizeof(long long));
    printf("sizeof(long long int)          : %d \n", sizeof(long long int));
    printf("sizeof(signed long long)       : %d \n", sizeof(signed long long));
    printf("sizeof(signed long long int)   : %d \n", sizeof(signed long long int));
    printf("sizeof(unsigned long long)     : %d \n", sizeof(unsigned long long));
    printf("sizeof(unsigned long long int) : %d \n", sizeof(unsigned long long int));
    printf("sizeof(float)                  : %d \n", sizeof(float));
    printf("sizeof(double)                 : %d \n", sizeof(double));
    printf("sizeof(long double)            : %d \n", sizeof(long double));
    printf("sizeof(void)                   : %d \n", sizeof(void));
    printf("\n");

    /* limits.h Macros */
    printf("limits.h Macros:\n");
    printf("CHAR_BIT   : %d\n", CHAR_BIT);
    printf("SCHAR_MIN  : %d\n", SCHAR_MIN);
    printf("SCHAR_MAX  : %d\n", SCHAR_MAX);
    printf("UCHAR_MAX  : %u\n", UCHAR_MAX);
    printf("CHAR_MIN   : %d\n", CHAR_MIN);
    printf("CHAR_MAX   : %d\n", CHAR_MAX);
    printf("SHRT_MIN   : %d\n", SHRT_MIN);
    printf("SHRT_MAX   : %d\n", SHRT_MAX);
    printf("USHRT_MAX  : %u\n", USHRT_MAX);
    printf("INT_MIN    : %d\n", INT_MIN);
    printf("INT_MAX    : %d\n", INT_MAX);
    printf("UINT_MAX   : %u\n", UINT_MAX);
    printf("LONG_MIN   : %ld\n", LONG_MIN);
    printf("LONG_MAX   : %ld\n", LONG_MAX);
    printf("ULONG_MAX  : %lu\n", ULONG_MAX);
    printf("LLONG_MIN  : %lld\n", LLONG_MIN);
    printf("LLONG_MAX  : %lld\n", LLONG_MAX);
    printf("ULLONG_MAX : %llu\n", ULLONG_MAX);
    printf("\n");

    /* float.h Macros */
    printf("float.h Macros:\n");
    printf("FLT_MIN  : %g\n", (float) FLT_MIN);
    printf("FLT_MAX  : %g\n", (float) FLT_MAX);
    printf("-FLT_MIN : %g\n", (float) -FLT_MIN);
    printf("-FLT_MAX : %g\n", (float) -FLT_MAX);
    printf("DBL_MIN  : %g\n", (double) DBL_MIN);
    printf("DBL_MAX  : %g\n", (double) DBL_MAX);
    printf("-DBL_MIN : %g\n", (double) -DBL_MIN);
    printf("-DBL_MAX : %g\n", (double) -DBL_MAX);
    printf("FLT_DIG  : %d\n", FLT_DIG);     // Float precision digits
    printf("DBL_DIG  : %d\n", DBL_DIG);     // Double precision digits
    printf("\n");

    return 0;
}
