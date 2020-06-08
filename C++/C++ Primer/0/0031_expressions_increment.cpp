#include <iostream>

using namespace std;

int main()
{
    // ADVICE: Use Postfix Operators only When Necessary
    //         The reason is simple: The prefix version avoids unnecessary work.
    //         It increments the value and returns the incremented version.
    //         The postfix operator must store the original value so that it can return
    //         the unincremented value as its result. If we don’t need the unincremented value,
    //         there’s no need for the extra work done by the postfix operator.

    int i = 0, j;
	j = ++i;    // i = 1, j = 1, prefix yields the incremented value
	cout << i << " " << j << endl;

	j = i++;    // i = 2, j = 1, postfix yields the unincremented value
	cout << i << " " << j << endl;

    j = --i;    // i = 1, j = 1, prefix yields the incremented value
	cout << i << " " << j << endl;

	j = i--;    // i = 0, j = 1, postfix yields the unincremented value
	cout << i << " " << j << endl;

	return 0;
}