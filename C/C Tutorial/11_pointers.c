#include <stdio.h>
#include <time.h>

/* Functions declaration */
void getSeconds(unsigned long *seconds);
unsigned long* getEpoch (void);
void delay (int number_of_seconds);


int main ()
{
    // NOTE: It is always a good practice to assign a NULL value to a pointer variable in case you do not have
    //       an exact address to be assigned.
    
    /* Pointer Addresses */
    int  var = 20;      // Variable declaration
    int  *ip = NULL;    // Pointer variable declaration

    ip = &var;      // Store the address of var in the pointer variable

    printf("Address of var variable: %x\n", &var);
    printf("Address stored in ip variable: %x\n", ip);
    printf("Value of *ip variable: %d\n", *ip);
    printf("\n");

    /* Pointer Arithmetic */
    const int MAX = 5;
    int  a[] = {10, 20, 30, 40, 50};
    int  i, *ptr;

    ptr = a;    // Store array address in pointer

    // Incrementing a Pointer
    for (i = 0; i < MAX; i++)
    {
        printf("&a[%d] = %x\n", i, ptr);
        printf("a[%d]  = %d\n", i, *ptr);

        ptr++;  // Move the pointer to the next address
    }

    printf("\n");

    // Decrementing a Pointer
    ptr = &a[MAX-1];

    for (i = MAX-1; i >= 0; i--)
    {
        printf("&a[%d] = %x\n", i, ptr);
        printf("a[%d]  = %d\n", i, *ptr);

        ptr--;  // Move the pointer to the previous address
    }

    printf("\n");

    // Pointer comparison
    ptr = a;
    i = 0;

    while (ptr <= &a[MAX-1])
    {
        printf("&a[%d] = %x\n", i, ptr);
        printf("a[%d]  = %d\n", i, *ptr);

        ptr++;  // Move the pointer to the next address
        i++;
    }

    printf("\n");

    /* Array of Pointers */
    // Array of pointers to int
    int *ptrArray[MAX];

    for (i = 0; i < MAX; i++)
    {
        ptrArray[i] = &a[i];    // assign the address of each array element to the each pointer in the array of pointers

        printf("*ptrArray[%d] = %d\n", i, *ptrArray[i] );
    }

    printf("\n");

    // Array of pointers to char
    char *names[] = {"Bruno", "Alexandre", "da", "Silva", "Grego"};

    for (i = 0; i < 5; i++)
    {
        printf("names[%d] = %s\n", i, names[i]);
    }

    printf("\n");

    /* Pointer to Pointer */
    int  **pptr;

    ptr = &var;     // Store the address of var
    pptr = &ptr;    // Store the address of ptr

    printf("Value of var = %d\n", var);
    printf("Value available at *ptr = %d\n", *ptr);
    printf("Value available at **pptr = %d\n", **pptr);

    printf("\n");

    /* Pass a pointer to a function */
    unsigned long sec;
    getSeconds(&sec);

    printf("getSeconds(&sec) = %ld\n", sec);

    printf("\n");

    delay(2);

    /* Return a pointer from a function */
    unsigned long *epoch;
    epoch = getEpoch();

    printf("Epoch: %ld\n", *epoch);

    printf("\n");

    return 0;
}


/* Functions definition */
void getSeconds (unsigned long *seconds)
{
    *seconds = time(NULL);
}

unsigned long* getEpoch (void)
{
    static unsigned long seconds;
    seconds = time(NULL);

    return &seconds;
}

void delay (int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}
