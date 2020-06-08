#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    string rsp;  // used in the condition; can't be defined inside the do

    // repeatedly ask the user for a pair of numbers to sum
    do
    {
        int val1 = 0, val2 = 0;

        cout << "please enter two values: ";

        cin  >> val1 >> val2;

        cout << "The sum of " << val1 << " and " << val2
             << " = " << val1 + val2 << "\n\n"
             << "More? Enter yes or no: ";

        cin  >> rsp;

    } while (!rsp.empty() && rsp[0] != 'n');

	cout << endl;

	unsigned i, mynum = 7;
	// guess number 7
	do
    {
		cout << "Guess a number between 0 and 9" << endl;

		cin >> i;

		if (i == mynum)
        {
			cout << "Congrats you guessed right!" << endl;
		}
		else
        {
            if (i < mynum)
            {
                cout << "too low" << endl;
            }
			else
            {
                cout << "too high" << endl;
            }
        }

	} while (i != mynum);

	return 0;
}