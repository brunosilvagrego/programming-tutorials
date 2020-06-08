#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstddef>

using namespace std;

// function that takes a reference to an int and sets the given object to zero
// i is just another name for the object passed to reset
void reset(int &i)
{
    i = 0;		// changes the value of the object to which i refers
}

// function that takes a pointer and sets the pointed-to value to zero
void reset(int *ip)
{
    *ip = 0;  	// changes the value of the object to which ip points
    ip = 0;   	// changes the local copy of ip; the argument is unchanged
}

// swaps i and j using references
void mySwap(int &i, int &j)
{
    int temp = i;
    i = j;
    j = temp;
}

// swaps i and j using pointers
void mySwap(int *i, int *j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}

// BEST PRACTICES:  Reference parameters that are not changed inside a function should be references to const.

// returns the index of the first occurrence of c in s
// the reference parameter occurs counts how often c occurs
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
    auto ret = s.size();    // position of the first occurrence, if any
    occurs = 0;             // set the occurrence count parameter

    for (decltype(ret) i = 0; i != s.size(); ++i)
    {
        if (s[i] == c)
        {
            if (ret == s.size())
            {
                ret = i;    // remember the first occurrence of c
            }

            ++occurs;       // increment the occurrence count
         }
	}

    return ret;            // count is returned implicitly in occurs
}

// returns an iterator that refers to the first occurrence of value
// the reference parameter occurs contains a second return value
vector<int>::const_iterator find_val(
    vector<int>::const_iterator beg,    // first element
    vector<int>::const_iterator end,    // one past last element
    int value,                          // the value we want
    vector<int>::size_type &occurs)     // number of times it occurs
{
    auto res_iter = end;    // res_iter will hold first occurrence, if any
    occurs = 0;             // set occurrence count parameter

    for ( ; beg != end; ++beg)
    {
        if (*beg == value)
        {

            if (res_iter == end)
            {
                res_iter = beg; // remember first occurrence of value
            }

            ++occurs;           // increment occurrence count
        }
    }

    return res_iter;            // count returned implicitly in occurs
}

int main()
{
    /** reset() test **/
    int j = 42;
	reset(j);	// j is passed by reference; the value in j is changed
	cout << "j = " << j  << endl;	// prints j = 0

	j = 42;		// restore the original value of j
	reset(&j);                     	// changes j but not the address of j
	cout << "j = "  << j << endl;  	// prints j = 0

	j = 42;    	// restore the original value of j
	int *p = &j;
	reset(p);	// changes object to which p points not the address in p
	cout << "j = "  << *p << endl;	// prints j = 0

    /* ---------------------------------------------------------------------------------------------- */
	int i = 0;
	const int ci = i;
    string::size_type ctr = 0;
    reset(&i);      // calls the version of reset that has an int* parameter
    reset(&ci);     // error: can't initialize an int* from a pointer to a const int object
    reset(i);       // calls the version of reset that has an int& parameter
    reset(ci);      // error: can't bind a plain reference to the const object ci
    reset(42);      // error: can't bind a plain reference to a literal
    reset(ctr);     // error: types don't match; ctr has an unsigned type
    find_char("Hello World!", 'o', ctr);    // ok: find_char's first parameter is a reference to const

    // NOTE: It is a somewhat common mistake to define parameters that a function does not
    //       change as (plain) references. Doing so gives the function’s caller the misleading
    //       impression that the function might change its argument’s value. Moreover, using a
    //       reference instead of a reference to const unduly limits the type of arguments that
    //       can be used with the function. As we’ve just seen, we cannot pass a const object, or
    //       a literal, or an object that requires conversion to a plain reference parameter.
    /* ---------------------------------------------------------------------------------------------- */

	/** mySwap() test **/
	int a = 17;
	int b = 10;

	cout << endl;
	cout << "a = "  << a << " b = " << b << endl;

	mySwap(a, b);       // references
	cout << "a = "  << a << " b = " << b << endl;

	mySwap(&a, &b);     // pointers
	cout << "a = "  << a << " b = " << b << endl;


    /** find_char() test **/
	string s;
    size_t ctr = 0;

    cout << endl;
	cout << "Say something: ";
	getline(cin, s);

	auto index = find_char(s, 'o', ctr);

    if (ctr == 0)
    {
        cout << "Character 'o' does not appear in string \"" << s << "\"\n" << endl;
    }
    else
    {
        cout << "Character 'o' appears first at index " << index << " and it appears " << ctr << " times in string \"" << s << "\"\n" << endl;
    }


	/** find_val() test **/
	vector<int> ivec;
	int i;

    cout << endl;
	cout << "Type integer values: ";

	// read values into ivec
	while (cin >> i)
    {
        ivec.push_back(i);
    }

	int arr[] = {42, 33, 92};  // define a local array to use

	for (auto i : arr)
    {
		auto it = find_val(ivec.begin(), ivec.end(), i, ctr);

		if (it == ivec.end())
        {
            cout << i << " is not in the input data" << endl;
        }
		else
        {
            cout << i << " was at position " << it - ivec.begin() << endl;
        }
	}

    return 0;
}
