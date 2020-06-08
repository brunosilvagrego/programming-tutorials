#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

// NOTE: There must always be a path through a recursive function that does not involve a
//       recursive call; otherwise, the function will recurse “forever,” meaning that the function
//       will continue to call itself until the program stack is exhausted. Such functions are
//       sometimes described as containing a recursion loop. In the case of factorial, the
//       stopping condition occurs when val is 1.

// factorial of val is val * (val - 1) * (val - 2) . . . * ((val - (val - 1)) * 1)
int factorial(int val)
{
    if (val > 1)
    {
        return factorial(val-1) * val;
    }

    return 1;
}


// NOTE: The main function may not call itself.

int main()
{
    int iVal;

    cout << "Type 1 integer for factorial: ";

	while (cin >> iVal)
    {
	    int j = factorial(iVal);
        cout << iVal << "! = " << j << endl;

        cout << "Type 1 integer for factorial: ";
	}

	return 0;
}