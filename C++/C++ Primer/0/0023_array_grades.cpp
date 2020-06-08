#include <iostream>
#include <string>
#include <vector>

using namespace std;

/** Data: 45 65 99 100 34 67 95 76 88 75 83 92 76 93 **/

int main()
{
    vector<unsigned> grades;

	// count the number of grades by clusters of ten:
	// 0--9, 10--19, . . . 90--99, 100

	unsigned scores[11] = {};   // 11 buckets, all value initialized to 0
	unsigned grade;

	while (cin >> grade)
    {
		if (grade <= 100)
        {
            ++scores[grade/10]; // increment the counter for the current cluster
        }

		grades.push_back(grade);
	}

	cout << "grades.size = " << grades.size() << endl;

	for (auto g : grades)       // for every element in grades
    {
        cout << g << " " ;
    }

	cout << endl;

	for (auto i : scores)       // for each counter in scores
    {
        cout << i << " ";       // print the value of that counter
    }

	cout << endl;

	return 0;
}