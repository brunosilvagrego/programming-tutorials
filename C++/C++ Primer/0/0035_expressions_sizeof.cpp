#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <bitset>

using namespace std;

struct Sales_data
{
	std::string bookNo;
	unsigned units_sold = 0;
	double revenue = 0.0;
};

int main()
{
    Sales_data data, *p;

	cout << "sizeof(Sales_data) = " << sizeof(Sales_data) << endl;      // size required to hold an object of type Sales_data
	cout << "sizeof data = " << sizeof data << endl;                    // size of data's type, i.e., sizeof(Sales_data)
	cout << "sizeof p = " << sizeof p << endl;                          // size of a pointer
	cout << "sizeof *p = " << sizeof *p << endl;                        // size of the type to which p points, i.e., sizeof(Sales_data)
	cout << "sizeof data.revenue = " << sizeof data.revenue << endl;    // size of the type of Sales_data's revenue member

	cout << "Sales_data[3]: " << sizeof(Sales_data[3]) << "\n"
	     << "Sales_data*: " << sizeof(Sales_data*) << "\n"
	     << "Sales_data&: " << sizeof(Sales_data&) << endl;

    cout << endl;

	cout << "short: " << sizeof(short) << "\n"
	     << "short[3]: " << sizeof(short[3]) << "\n"
	     << "short*: " << sizeof(short*) << "\n"
	     << "short&: " << sizeof(short&) << endl;

	cout << endl;

	cout << "int: " << sizeof(int) << "\n"
	     << "int[3]: " << sizeof(int[3]) << "\n"
	     << "int*: " << sizeof(int*) << "\n"
	     << "int&: " << sizeof(int&) << endl;

	cout << endl;


	int x[10];
	int *ip = x;

	// Array size
	cout << "sizeof(x) = " << sizeof(x) << endl;

	// number of elements in x
	cout << "sizeof(x)/sizeof(*x) = " << sizeof(x)/sizeof(*x) << endl;

	// divides sizeof a pointer by sizeof an int
	cout << "sizeof(ip)/sizeof(*ip) = " << sizeof(ip)/sizeof(*ip) << endl;

	return 0;
}