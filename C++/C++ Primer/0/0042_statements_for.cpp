#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
	vector<int> v = {0,1,2,3,4,5,6,7,8,9};
	vector<int> orig = v;

	/* range for */
	// range variable must be a reference so we can write to the elements
	for (auto &r : v)   // for each element in v
    {
        r *= 2;         // double the value of each element in v
    }

    cout << "v: ";

	for (int r : v)
    {
        cout << r << " "; // print the elements in v
    }

	cout << '\n' << endl;

	v = orig;

	/* traditional for */
	for (auto beg = v.begin(); beg != v.end(); ++beg)
    {
        auto &r = *beg; // r must be a reference so we can change the element
        r *= 2;         // double the value of each element in v
    }

    cout << "v: ";

    for (unsigned i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " "; // print the elements in v
    }

    cout << endl;

	return 0;
}