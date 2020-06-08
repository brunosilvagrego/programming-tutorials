#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstddef>

using namespace std;

/* ------------------------------------------------------------------------------------------- */
// despite appearances, these three declarations of print are equivalent
// each function has a single parameter of type const int*
void print(const int*);
void print(const int[]);    // shows the intent that the function takes an array
void print(const int[10]);  // dimension for documentation purposes (at best)

// NOTE: If we pass an array to print, that argument is automatically converted to a pointer
//       to the first element in the array; the size of the array is irrelevant.

// WARNING: As with any code that uses arrays, functions that take array parameters must
//          ensure that all uses of the array stay within the array bounds.

// BEST PRACTICES: When a function does not need write access to the array elements, the
//                 array parameter should be a pointer to const. A parameter should be
//                 a plain pointer to a nonconst type only if the function needs to change
//                 element values.
/* ------------------------------------------------------------------------------------------- */

// prints a null-terminated array of characters
void print(const char *cp)
{
	if (cp)                 // if cp is not a null pointer
    {
        while (*cp)         // so long as the character it points to is not a null character
        {
            cout << *cp++;  // print the character and advance the pointer
        }
    }
}

// print ints in the given range
void print(const int *beg, const int *end)
{
	// print every element starting at beg up to but not including end
    while (beg != end)
    {
        cout << *beg++ << " ";  // print the current element and advance the pointer
    }

}

// print ints in the given range
void print(const int ia[], size_t size)
{
    for (size_t i = 0; i != size; ++i)
    {
        cout << ia[i] << " ";
    }
}

/* ------------------------------------------------------------------------------------------- */
void f(int &arr[10]);   // error: declares arr as an array of references
void f(int (&arr)[10]); // ok: arr is a reference to an array of ten ints
/* ------------------------------------------------------------------------------------------- */

// ok: parameter is a reference to an array; the dimension is part of the type
void print(int (&arr)[10])
{
    for (auto elem : arr)
    {
        cout << elem << " ";
    }
}

/* ------------------------------------------------------------------------------------------- */
int *matrix[10];    // array of ten pointers
int (*matrix)[10];  // pointer to an array of ten ints
/* ------------------------------------------------------------------------------------------- */

// matrix points to the first element in an array whose elements are arrays of ten ints
void print(int (*matrix)[10], int rowSize)
{
    for (size_t i = 0; i < rowSize; ++i)
    {
        for (size_t j = 0; j < 10; ++j)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

// equivalent definition
void print(int matrix[][10], int rowSize);


int main()
{
    /** print(const char *cp) **/
    print("hi world!"); // calls first version of print
	cout << '\n' << endl;


	/** print(const int *beg, const int *end) **/
    // j is converted to a pointer to the first element in j
    // the second argument is a pointer to one past the end of j
    int j[3] = {0, 1, 2};
    print(begin(j), end(j));  // library begin and end functions
	cout << '\n' << endl;

	// equivalent call, directly calculate the begin and end pointers
	print(j, j + 3);
	cout << '\n' << endl;


	/** print(const int ia[], size_t size) **/
	print(j, end(j) - begin(j));
	cout << '\n' << endl;

	
	/** print(int (&arr)[10]) **/
	int i = 0;
    int k[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    print(&i);  // error: argument is not an array of ten ints
    print(j);   // error: argument is not an array of ten ints
    print(k);   // ok: argument is an array of ten ints
    cout << '\n' << endl;

    
    /** print(int (*matrix)[10], int rowSize) **/
    int matrix[3][10] = {
	    { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10},
	    {11, 12, 13, 14, 15, 16, 17, 18, 19, 20},
	    {21, 22, 23, 24, 25, 26, 27, 28, 29, 30}
	};

	print(matrix, 3);

    return 0;
}
