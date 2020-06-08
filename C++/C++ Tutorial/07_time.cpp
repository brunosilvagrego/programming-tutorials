#include <iostream>
#include <ctime>

using namespace std;


int main()
{
    // Current date/time based on current system
    time_t now = time(0);

    // Convert now to string form
    char* dt = ctime(&now);

    cout << "Local Time : " << dt << endl;

    // Convert now to tm struct for UTC
    tm *gmtm = gmtime(&now);
    dt = asctime(gmtm);

    cout << "UTC        : " << dt << endl;

    // Epoch => Number of sec since January 1, 1970
    cout << "Epoch      : " << now << "\n" << endl;

    // Components of the tm structure
    tm *ltm = localtime(&now);

    cout << "Date       : " << ltm->tm_mday << "/";

    if ((1 + ltm->tm_mon) < 10)
    {
        cout << "0";
    }

    cout << 1 + ltm->tm_mon << "/" << 1900 + ltm->tm_year << endl;

    cout << "Time       : " << ltm->tm_hour << ":" << ltm->tm_min << ":";

    if (ltm->tm_sec < 10)
    {
        cout << "0";
    }

    cout << ltm->tm_sec << endl;

    return 0;
}
