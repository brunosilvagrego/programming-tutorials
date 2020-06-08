#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    /* Vectors Initialization (1) */
	vector<string> articles = {"a", "an", "the"};
	cout << "articles.size() = " << articles.size() << endl;
	cout << "articles[0] = " << articles[0] << endl;
	cout << "articles[1] = " << articles[1] << endl;
	cout << "articles[2] = " << articles[2] << endl;


	/* Vectors Initialization (2) */
	vector<string> svec;            // default initialization; svec has no elements
	vector<int> ivec;               // ivec holds objects of type int

	vector<vector<string>> file;  	// vector whose elements are vectors
	vector<vector<int>> vecOfvec; 	// each element is itself a vector

	// all five vectors have size 0
	cout << endl;
	cout << svec.size() << " " << ivec.size() << " "
	     << file.size() << " " << vecOfvec.size() << endl;


	/* Vectors Initialization (3) */
	vector<int> ivec2(10);              // ten elements, each initialized to 0
	vector<int> ivec3(10, -1);          // ten int elements, each initialized to -1
	vector<string> svec2(10);           // ten elements, each an empty string
	vector<string> svec3(10, "hi!");    // ten strings; each element is "hi!"

	// all five vectors have size 10
	cout << endl;
	cout << ivec2.size() << " " << ivec3.size() << " "
	     << svec2.size() << " " << svec3.size() << endl;


	/* Vectors Initialization (4) */
	// 10 is not a string, so cannot be list initialization
	vector<string> v1(10);          // construct v1 with ten value-initialized elements
	vector<string> v2{10};          // ten elements value-initialized elements
	vector<string> v3(10, "hi");    // ten elements with value "hi"
	vector<string> v4{10, "hi"};    // ten elements with values "hi"

	// all four vectors have size 10
	cout << endl;
	cout << v1.size() << " " << v2.size()
	     << " " << v3.size() << " " << v4.size() << endl;

	/* Vectors Initialization (5) */
	vector<int> v5(10, 1);  // ten elements with value 1
	vector<int> v6;
	v6.push_back(10);
	v6.push_back(1);

	// v5 has size 10 and v6 has size 2
	cout << endl;
	cout << v5.size() << " " << v6.size() << endl;
	cout << endl;


	/* Vector square values */
	vector<int> v{1,2,3,4,5,6,7,8,9};

	for (auto &i : v)       // for each element in v (note: i is a reference)
    {
        i *= i;             // square the element value
    }

	for (auto i : v)        // for each element in v
    {
        cout << i << " ";   // print the element
    }

	return 0;
}