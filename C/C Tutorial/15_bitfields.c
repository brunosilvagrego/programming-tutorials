#include <stdio.h>

/* Define a simple structure */
struct status1
{
    unsigned int flag1;
    unsigned int flag2;
};

/* Define a structure with bit fields */
struct status2
{
    unsigned int flag1 : 1;
    unsigned int flag2 : 1;
};

/* Define a structure with bit fields */
struct PersonAge
{
   unsigned int age : 3;
};

int main ()
{
    printf("sizeof(struct status1) = %d\n", sizeof(struct status1));
    printf("sizeof(struct status2) = %d\n", sizeof(struct status2));

    struct PersonAge pa;

    pa.age = 4;
    printf("\nsizeof(struct PersonAge) = %d\n", sizeof(struct PersonAge));
    printf("pa.age = %d\n", pa.age);

    pa.age = 7;
    printf("pa.age = %d\n", pa.age);

    pa.age = 8;
    printf("pa.age = %d\n", pa.age);

    return 0;
}
