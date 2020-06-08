#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

/** Data: 10 20 30 40 50 60 70 75 80 90 95 100 $ **/

int main()
{
    unsigned gval;
    vector<unsigned> grades;

	while (cin >> gval)
    {
        grades.push_back(gval);
    }

    cout << endl;

	for (auto grade : grades)
    {
		string finalgrade = (grade < 60) ?  "fail" : "pass";

		cout << grade << " " + finalgrade << endl;
	}

	cout << endl;

	for (auto grade : grades)
    {
		string finalgrade = (grade > 90) ? "high pass" : (grade < 60) ? "fail" : "pass";

		cout << grade << " " + finalgrade << endl;
	}

	cout << endl;

	// WARNING: Nested conditionals quickly become unreadable. It’s a good idea to nest no more than two or three.

	for (auto grade : grades)
    {
		string finalgrade = (grade > 90) ? "high pass" : (grade <= 75 && grade >= 60) ? "low pass" : (grade < 60) ? "fail" : "pass";

		cout << grade << " " + finalgrade << endl;
	}

	cout << endl;

	for (auto grade : grades)
    {
		string finalgrade;

		if (grade > 90)
        {
            finalgrade = "high pass";
        }
        else if (grade <= 75 && grade >= 60)
        {
            finalgrade = "low pass";
        }
        else if (grade < 60)
        {
            finalgrade = "fail";
        }
        else
        {
            finalgrade = "pass";
        }

		cout << grade << " " + finalgrade << endl;
	}

	cout << endl;

	
	int grade = 75;
	cout << ((grade < 60) ?  "fail" : "pass");  // prints pass or fail
	cout << endl;

	cout << (grade < 60) ?  "fail" : "pass";    // prints 1 or 0!
	cout << endl;

	// previous expression is equivalent to the following
	cout << (grade < 60);       // prints 1 or 0
	cout ?  "fail" : "pass";    // no print; test cout and then yield one of the two literal depending on whether cout is true or false
	cout << endl;

    cout << grade < 60 ? "fail" : "pass";       // error: compares cout to 60
	
	
	int i = 15, j = 20;
	cout << (i < j ? i : j);    // OK: prints smaller of i and j
	cout << endl;

	cout << (i < j) ? i : j;    // OK: prints 1 or 0!
	cout << endl;

	// previous expression is equivalent to the following
	cout << (i < j);            // prints 1 or 0
	cout ? i : j;               // no print; test cout and then evaluate i or j depending on whether cout evaluates to true or false
	cout << endl;

	return 0;
}