#include <iostream>
#include <string>
#include <iterator>
#include <cstddef>

using namespace std;

int main()
{
    constexpr size_t sz = 5;
    int arr[sz] = {1,2,3,4,5};
    int *ip = arr;      // equivalent to int *ip = &arr[0]
    int *ip2 = ip + 4;  // ip2 points to arr[4], the last element in arr

    cout << "*ip = " << *ip << endl;
    cout << "*ip2 = " << *ip2 << endl;
    cout << endl;

    // ok: arr is converted to a pointer to its first element; p points one past the end of arr
    int *p = arr + sz;  // use caution -- do not dereference!
    int *p2 = arr + 10; // error: arr has only 5 elements; p2 has undefined value

    // WARNING: Computing a pointer more than one past the last element is an error, although the
    //          compiler is unlikely to detect such errors.

    auto n = end(arr) - begin(arr);             // n is 5, the number of elements in arr
    ptrdiff_t n2 = (end(arr) - begin(arr)) + 1; // n2 is 6

    cout << "n = " << n << endl;
    cout << "n2 = " << n2 << endl;
    cout << endl;

    // WARNING: The result of subtracting two pointers is a library type named ptrdiff_t. Like size_t,
    //          the ptrdiff_t type is a machine-specific type and is defined in the cstddef
    //          header. Because subtraction might yield a negative distance, ptrdiff_t is a signed
    //          integral type.

    int ia[] = {0,2,4,6,8}; // array with 5 elements of type int
    int last = *(ia + 4);   // ok: initializes last to 8, the value of ia[4]

    cout << "last = *(ia + 4);" << endl;
    cout << "last = " << last << endl;
    cout << endl;

    last = *ia + 4;         // ok: last = 4, equivalent to ia[0] + 4

    cout << "last = *ia + 4;" << endl;
    cout << "last = " << last << endl;
    cout << endl;

    int i = ia[2];          // ia is converted to a pointer to the first element in ia; ia[2] fetches the element to which (ia + 2) points

    cout << "i = ia[2];" << endl;
    cout << "i = " << i << endl;
    cout << endl;

    int *ptr = ia;          // ptr points to the first element in ia
    i = *(ptr + 2);         // equivalent to i = ia[2]

    cout << "int *ptr = ia;" << endl;
    cout << "i = *(ptr + 2);" << endl;
    cout << "i = " << i << endl;
    cout << endl;

    int *ptr2 = &ia[2];     // ptr2 points to the element indexed by 2
    int j = ptr2[1];        // ptr2[1] is equivalent to *(ptr2 + 1), ptr2[1] is the same element as ia[3]
    int k = ptr2[-2];       // p[-2] is the same element as ia[0]

    cout << "j = " << j << endl;
    cout << "k = " << k << endl;
    cout << endl;

    // WARNING: Unlike subscripts for vector and string, the index of the built-in subscript operator is not an unsigned type.

	return 0;
}