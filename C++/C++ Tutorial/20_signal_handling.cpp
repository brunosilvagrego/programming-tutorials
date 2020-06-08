#include <iostream>
#include <csignal>
#include <ctime>

using namespace std;


// Signals Description:
//      SIGABRT - Abnormal termination of the program, such as a call to abort.
//      SIGFPE  - An erroneous arithmetic operation, such as a divide by zero or an operation resulting in overflow.
//      SIGILL  - Detection of an illegal instruction.
//      SIGINT  - Receipt of an interactive attention signal.
//      SIGSEGV - An invalid access to storage.
//      SIGTERM - A termination request sent to the program.


void delay (int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // Looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void signalHandler (int signum)
{
    cout << "Interrupt signal (" << signum << ") received.\n";

   // Cleanup and close up stuff here

   exit(signum);    // Terminate the program
}


int main ()
{
    int i = 0;

    // Register signal SIGINT and signal handler
    signal(SIGINT, signalHandler);

    // Infinite Loop
    while (1)
    {
        cout << "Going to sleep ..." << endl;

        delay(1);   // Sleep for 1 second

        i++;

        if (i == 3)
        {
            raise(SIGINT);  // Generate signal
        }
    }

    return 0;
}
