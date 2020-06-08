#include <vector>
using std::vector;

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;

#include <initializer_list>
using std::initializer_list;

#include <sstream>
using std::ostringstream;


struct ErrCode {
	ErrCode(int i) : num(i) { }  // initializes objects of type ErrCode
	
    string msg()                 // member function of ErrCode
	{
        ostringstream s;
        s << "ErrCode " << num;
        return s.str();
    }

	int num;  // data member, note uninitialized
};


void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";

	for (const auto &elem : il)
    {
        cout << elem << " " ;
    }

	cout << endl;
}

// overloaded version takes only a list of strings
void error_msg(initializer_list<string> il)
{
	for (auto beg = il.begin(); beg != il.end(); ++beg)
    {
        cout << *beg << " " ;
    }

	cout << endl;
}

// overloaded version that takes only pointers to a range of strings
void error_msg(const string *beg, const string *end)
{
	while (beg != end)
    {
        cout << *beg++ << " " ;
    }

	cout << endl;
}

// function to illustrate list initializing return value
vector<string> functionX()
{
	string expected = "description", actual = "some other case";

	if (expected.empty())
    {
        return {};  // return an empty vector
    }
	else if (expected == actual)
    {
        return {"functionX", "okay"};   // return list-initialized vector
    }
	else
    {
        return {"functionX", expected, actual};
    }
}

// sums list values
void sumList(initializer_list<int> li)
{
    int sum = 0;
	for (auto beg = li.begin(); beg != li.end(); ++beg)
    {
        sum += *beg;
    }

    cout << "sumList = " << sum << " " << endl;
}

int main()
{
	string expected = "description", actual = "some other case";

	/** error_msg(initializer_list<string> il) **/
	// expected, actual are strings
	if (expected != actual)
    {
        error_msg({"functionX", expected, actual});
    }
	else
    {
        error_msg({"functionX", "okay"});
    }

    cout << endl;


    /** error_msg(ErrCode e, initializer_list<string> il) **/
	// expected, actual are strings
	if (expected != actual)
    {
        error_msg(ErrCode(42), {"functionX", expected, actual});
    }
	else
    {
        error_msg(ErrCode(0), {"functionX", "okay"});
    }


    /** error_msg(initializer_list<string> il) **/
	// can pass an empty list, calls second version of error_msg
	error_msg({}); // prints blank line


	/** functionX() **/
	// call function that list initializes its return value
	// results is a vector<string>
	auto results = functionX();

	for (auto i : results)
    {
        cout << i << " ";
    }

	cout << '\n' << endl;

	/* ---------------------------------------------------------------------------------------------- */
	// NOTE: Unlike vector, the elements in an initializer_list are always const values;
    //       there is no way to change the value of an element in an initializer_list.
    //       The begin and end operations on initializer_list objects are analogous to the
    //       corresponding vector members
    /* ---------------------------------------------------------------------------------------------- */

	/** sumList(initializer_list<int> li) **/
	initializer_list<int> li = {0, 1, 2, 3};

	sumList(li);

	/* ---------------------------------------------------------------------------------------------- */
	// NOTE: Ellipsis parameters are in C++ to allow programs to interface to C code that uses a C
    //       library facility named varargs. Generally an ellipsis parameter should not be used for
    //       other purposes. Your C compiler documentation will describe how to use varargs.

    // WARNING: Ellipsis parameters should be used only for types that are common to both C
    //          and C++. In particular, objects of most class types are not copied properly
    //          when passed to an ellipsis parameter.
    /* ---------------------------------------------------------------------------------------------- */

    return 0;
}
