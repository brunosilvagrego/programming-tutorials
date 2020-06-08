#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    cout << "v1 before: ";

    for (auto i : v1)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

    for (auto it = v1.begin(); it != v1.end(); it++)
    {
        *it = *it * 2;
    }

    cout << "v1 after: ";

    for (auto i : v1)
    {
        cout << i << " ";
    }

    cout << endl;
    cout << endl;

	return 0;
}