#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    vector<int> ivec;
    int cnt = 10;

    // NOTE: One common use for the comma operator is in a for loop:
    //       This loop increments i and decrements cnt in the expression in the for header.

    // add elements 10 . . . 1 to ivec
    for(unsigned i = 0; i < 10; ++i, --cnt)
    {
        ivec.push_back(cnt);
    }

    cout << "ivec: ";

    for (auto ival : ivec)
    {
        cout << ival << " ";
    }

    cout << endl;

	return 0;
}