#include <stdio.h>
#include <string.h>

struct Data_St
{
    int i;
    float f;
    char str[20];
};


// NOTE: A union is a special data type available in C that allows to
//       store different data types in the same memory location.

union Data
{
    int i;
    float f;
    char str[20];
};

int main ()
{
    printf("sizeof(struct Data_St) = %d\n", sizeof(struct Data_St));
    printf("sizeof(union Data) = %d\n\n", sizeof(union Data));

    union Data data;

    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "C Programming");

    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n\n", data.str);

    data.i = 10;
    printf("data.i : %d\n", data.i);

    data.f = 220.5;
    printf("data.f : %f\n", data.f);

    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);

    return 0;
}
