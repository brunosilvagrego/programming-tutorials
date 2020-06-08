#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstdlib>

using namespace std;


// function swap with return
void swap(int &v1, int &v2)
{
    // if the values are already the same, no need to swap, just return
    if (v1 == v2)
    {
        return;     // return is analogous to the use of a break statement to exit a loop
    }

    // if we're here, there's work to do
    int tmp = v2;
    v2 = v1;
    v1 = tmp;

    // implicit return; no explicit return necessary
}


// incorrect return values, this code will not compile
bool str_subrange(const string &str1, const string &str2)
{
    // same sizes: return normal equality test
    if (str1.size() == str2.size())
    {
        return str1 == str2;    // ok: == returns bool
    }

    // find the size of the smaller string; conditional operator
    auto size = (str1.size() < str2.size()) ? str1.size() : str2.size();

    // look at each element up to the size of the smaller string
    for (decltype(size) i = 0; i != size; ++i)
    {
        if (str1[i] != str2[i])
        {
            // return; // error #1: no return value; compiler should detect this error
            return false;
        }
    }

    // error #2: control might flow off the end of the function without a return the compiler might not detect this error

    // WARNING: Failing to provide a return after a loop that contains a return is an error.
    //          However, many compilers will not detect such errors.
}


// make plurals
string make_plural(size_t ctr, const string &word,  const string &ending)
{
	return (ctr > 1) ? word + ending : word;
}


// The parameters and return type are references to const string. The strings are
// not copied when the function is called or when the result is returned.
// return a reference to the shorter of two strings
const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}


// disaster: this function returns a reference to a local object
const string &manip()
{
    string ret = "temp";

    if (!ret.empty())
    {
        return ret;     // WRONG: returning a reference to a local object!
    }
    else
    {
        return "Empty"; // WRONG: "Empty" is a local temporary string
    }
}

/* ------------------------------------------------------------------------------------------------- */
// NOTE: When a function completes, its storage is freed. After a function
//       terminates, references to local objects refer to memory that is no longer valid.
//
//       For the same reasons that it is wrong to return a reference to a local object, it is
//       also wrong to return a pointer to a local object. Once the function completes, the local
//       objects are freed. The pointer would point to a nonexistent object.

// TIP: One good way to ensure that the return is safe is to ask: To what preexisting
//      object is the reference referring?
/* ------------------------------------------------------------------------------------------------- */


// get returns a reference to an element in the given array
int &get(int *arry, int index)
{
    return arry[index];
}


int main()
{
    /** swap(int &v1, int &v2) **/
    int i = 0;
    int j = 0;

    cout << "i = " << i << ", j = " << j << endl;

    i = 5;
    cout << "i = " << i << ", j = " << j << endl;

    swap(i, j);
    cout << "i = " << i << ", j = " << j << endl;
    cout << endl;


    /** make_plural(size_t ctr, const string &word,  const string &ending) **/
    size_t cnt = 1;
	cout << make_plural(cnt, "success", "es") << endl;
	cout << make_plural(cnt, "failure", "s") << endl;

	cnt = 2;
	cout << make_plural(cnt, "success", "es") << endl;
	cout << make_plural(cnt, "failure", "s") << endl;
	cout << endl;


	/** string &shorterString(const string &s1, const string &s2) **/
    string s1 = "Test";
    string s2 = "Hello";
    string shorter = shorterString(s1, s2);

    cout << "The shorter string is: " << shorter << endl;
    cout << "The shorter string size is: " << shorterString(s1, s2).size() << endl;
	cout << endl;


	/** &get(int *arry, int index) **/
	int ia[10];     // array of ten uninitialized ints

    for (int i = 0; i != 10; ++i)
    {
        get(ia, i) = i;     // call get to assign values to the elements
    }

    // shorterString("hi", "bye") = "X"; // error: return value is const

	for (auto i : ia)
	{
	    cout << i << " ";   // print the elements
	}

	cout << endl;


	/* ------------------------------------------------------------------------------------------------- */
    // NOTE: There is one exception to the rule that a function with a return type other than void
    //       must return a value: The main function is allowed to terminate without a return. If
    //       control reaches the end of main and there is no return, then the compiler implicitly
    //       inserts a return of 0.
    //
    //       The value returned from main is treated as a status
    //       indicator. A zero return indicates success; most other values indicate failure. A nonzero
    //       value has a machine-dependent meaning.
    /* ------------------------------------------------------------------------------------------------- */

	/** main return **/
	bool some_failure = false;
    if (some_failure)
        return EXIT_FAILURE;  // defined in cstdlib
    else
        return EXIT_SUCCESS;  // defined in cstdlib

}
