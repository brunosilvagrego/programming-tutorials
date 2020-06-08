#include <iostream>
#include <string>
#include <iterator>
#include <cstddef>

using namespace std;

int main()
{
    int ia[] = {0,1,2,3,4,5,6,7,8,9};
	int *p = ia;    // p points to the first element in ia

	cout << *p << endl;

	++p;            // p points to ia[1]

	cout << *p << endl;
	cout << endl;

	int *e = &ia[10];   // pointer just past the last element in ia

    // NOTE: A pointer “one past” the end of a built-in array behaves the same way as the
    //       iterator returned by the end operation of a vector. In particular, we may
    //       not dereference or increment an off-the-end pointer.

	cout << "ia: ";

	for (int *b = ia; b != e; b++)
    {
        cout << *b << " "; // print the elements in ia
    }

	cout << endl;

	const size_t sz = 10;
	int arr[sz];        // array of 10 ints

	cout << endl;
	cout << "Type 10 ints: ";
	/** Data: 2 4 6 8 10 -12 14 16 18 20 **/

	for (auto &n : arr) // for each element in arr
    {
        cin >> n;       // read values from the standard input
    }

    cout << "arr: ";

	for (auto i : arr)
    {
        cout << i << " ";
    }

	cout << endl;

	int *pbeg = begin(arr);     // pbeg points to the first element of arr
	int *pend = end(arr);       // pend points just past the last element in arr

	// find the first negative element,
	// stopping if we've seen all the elements
	while (pbeg != pend && *pbeg >= 0)
    {
        pbeg++;
    }

	if (pbeg == pend)
    {
        cout << "no negative elements in arr" << endl;
    }
	else
    {
        cout << "first negative number was " << *pbeg << endl;
    }

	return 0;
}