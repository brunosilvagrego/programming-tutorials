#include <iostream>
#include <string>

using namespace std;

int main()
{
    string line;

	// Read input a line at a time and discard blank lines
	// The newline that causes getline to return is discarded; the newline is not stored in the string.
	while (getline(cin, line))
    {
        if (!line.empty())
        {
            cout << line << endl;
        }
    }

	return 0;
}