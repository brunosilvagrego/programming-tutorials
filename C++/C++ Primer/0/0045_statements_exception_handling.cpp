#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <stdexcept>

using namespace std;

int main()
{
    int ival1, ival2;

    cout << "Type 2 integers for division: ";

	while (cin >> ival1 >> ival2)
    {
	    try
	    {
	        // execute code that will divide the two integers
	        // if the division fails, the code throws a runtime_error exception
	        // first check that the second integer is equal to 0
	        if (ival2 == 0)
	        {
	            throw runtime_error("Divisor must not be equal to 0!");
	        }

	        // if we're still here, ival2 is not equal to 0
	        cout << "ival1 / ival2 =  " << ival1 / ival2 << endl;
	    }
	    catch (runtime_error err)
	    {
	        // remind the user that the ival2 must not be equal to 0
	        cout << err.what() << "\nTry Again?  Enter y or n" << endl;

	        char c;
	        cin >> c;
	        if (!cin || c == 'n')
            {
                break;      // break out of the while loop
            }
	    } // ends the catch clause

	    cout << "Type 2 integers for division: ";
	} // ends the while loop

	return 0;
}