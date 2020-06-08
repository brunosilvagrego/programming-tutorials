#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

// NOTE: Each local static object is initialized before the first time execution passes through the object’s definition.
//       Local statics are not destroyed when a function ends; they are destroyed when the program terminates.

size_t count_calls()
{
	static size_t ctr = 0;  // value will persist across calls
	return ++ctr;
}

int main()
{
	for (size_t i = 0; i != 10; ++i)
    {
        cout << count_calls() << endl;
    }

	return 0;
}