#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

/** Data: how now now now brown cow cow down down down down cow cow cow $ **/

int main()
{
    string previousStr = "";
    string currentStr = "";
    unsigned cnt = 1;

    // NOTE: Variables defined in a while condition or while body are created and destroyed on each iteration.
    while (cin >> currentStr && currentStr != "$")
    {
        if (currentStr == previousStr)
        {
            ++cnt;
        }
        else
        {
            if (previousStr != "")
            {
                cout << "String " << previousStr << " occurred " << cnt << " times" << endl;
            }

            cnt = 1;
        }

        previousStr = currentStr;
    }

    cout << "String " << previousStr << " occurred " << cnt << " times" << endl;

	return 0;
}