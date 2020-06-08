#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 5

void *PrintHello (void *threadid)
{
    long tid;
    tid = (long)threadid;
    printf("\nRunning Thread ID: %d\n", tid);
    pthread_exit(NULL);
}


int main ()
{
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        printf("\nmain(): creating thread #%d\n", i);

        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

        if (rc)
        {
            printf("Error: unable to create thread, %d\n", rc);
            exit(EXIT_FAILURE);
        }
    }

    pthread_exit(NULL);

    return 0;
}
