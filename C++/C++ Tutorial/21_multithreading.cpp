#include <iostream>
#include <ctime>
#include <cstdlib>
#include <pthread.h>

using namespace std;

#define NUM_THREADS 3

// NOTE: The maximum number of threads that may be created by a process is implementation dependent.
//       Once created, threads are peers, and may create other threads. There is no implied hierarchy
//       or dependency between threads.

void delay (int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void *PrintHello(void *threadid)
{
    long tid;
    tid = (long)threadid;

    cout << "Hello World! Thread ID: " << tid << endl;

    pthread_exit(NULL);

    return 0;
}

void *wait (void *t)
{
    long tid;

    tid = (long) t;

    cout << "\nSleeping in thread #" << tid << endl;
    delay(5);

    cout << "\nThread ID: " << tid << "  ... exiting " << endl;

    pthread_exit(NULL);

    return 0;
}


int main ()
{
    /* PrintHello() */
    pthread_t threads[NUM_THREADS];
    int rc;
    int i;

    for (i = 0; i < NUM_THREADS; i++)
    {
        delay(1);

        cout << "\nmain() - creating thread #" << i << endl;
        rc = pthread_create(&threads[i], NULL, PrintHello, (void *)i);

        if (rc)
        {
            cout << "Error - unable to create thread: " << rc << endl;
            exit(-1);
        }
    }


    /* wait() */
    pthread_attr_t attr;
    void *status;

    // NOTE: The pthread_join() subroutine blocks the calling thread until the specified 'threadid' thread
    //       terminates. When a thread is created, one of its attributes defines whether it is joinable or detached.
    //       Only threads that are created as joinable can be joined. If a thread is created as detached, it can never be joined.

    // Initialize and set thread joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    for (i = 0; i < NUM_THREADS; i++)
    {
        delay(1);

        cout << "\nmain() - creating thread #" << i << endl;

        rc = pthread_create(&threads[i], &attr, wait, (void *)i);

        if (rc)
        {
            cout << "Error - unable to create thread: " << rc << endl;
            exit(-1);
        }
    }

    // Free attribute and wait for the other threads
    pthread_attr_destroy(&attr);

    for (i = 0; i < NUM_THREADS; i++)
    {
        delay(1);

        rc = pthread_join(threads[i], &status);

        if (rc)
        {
            cout << "Error - unable to join thread: " << rc << endl;
            exit(-1);
        }

        cout << "\nmain() - completed thread id: " << i << "  exiting with status: " << status << endl;
    }

    pthread_exit(NULL);


    return 0;
}
