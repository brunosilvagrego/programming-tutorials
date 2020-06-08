#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Data: 45 65 99 100 34 67 95 76 88 75 83 92 76 93 */

int main()
{
    // hold the grades we read from the standard input
	vector<unsigned> grades;

	// count the number of grades by clusters of ten:
	// 0--9, 10--19, . ..  90--99, 100
	vector<unsigned> scores(11, 0); // 11 buckets, all initially 0

	unsigned grade;

	// read the grades
	while (cin >> grade)
    {
		if (grade <= 100)       // handle only valid grades
		{
		    grades.push_back(grade);
			++scores[grade/10]; // increment the counter for the current cluster
		}
	}

	// print grades
	cout << "grades.size = " << grades.size() << endl;
	for (auto i : grades)
    {
        cout << i << " " ;
    }

	cout << endl;

	// print scores
	cout << "scores.size = " << scores.size() << endl;
	for (auto i : scores)
    {
        cout << i << " " ;
    }

	cout << endl;

	return 0;
}