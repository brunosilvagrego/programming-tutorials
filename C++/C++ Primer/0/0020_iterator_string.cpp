#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str("some string");
    string orig = str;

	/** Print the first character in str **/
	if (!str.empty())   // make sure there's a character to print
    {
        cout << str[0] << endl;
    }


    /** Convert to uppercase the first character in str **/
	if (!str.empty())   // make sure there's a character in str[0]
    {
        str[0] = toupper(str[0]);   // assign a new value to the first character in str
    }

    cout << '\n' << str << endl;


    /** Print the first character in str using iterators instead of subscripts **/
	str = orig; // restore str to its original value

	if (str.begin() != str.end())   // make sure str is not empty
    {
		auto it = str.begin();      // it denotes the first character in str
		*it = toupper(*it);         // make that character uppercase
	}

	cout << '\n' << str << endl;


	/** Four ways to capitalize first word in str: **/

	/* 1. for loop with subscripts */
	str = orig; // restore str to its original value

	for (decltype(str.size()) index = 0; index < str.size() && !isspace(str[index]); ++index)
    {
        str[index] = toupper(str[index]);   // capitalize the current character
    }

	cout << '\n' << str << endl;

	/* 2. for loop with iterators instead of subscripts */
	str = orig; // restore str to its original value

	for (auto it = str.begin(); it != str.end() && !isspace(*it); ++it)
    {
        *it = toupper(*it);         // capitalize the current character
    }

	cout << '\n' << str << endl;

    /* 3. while instead of a for with subscripts */
	str = orig; // restore str to its original value

	decltype(str.size()) index = 0; // subscript to look at characters in str

	while (index < str.size() && !isspace(str[index]))
    {
		str[index] = toupper(str[index]);   // capitalize the current character
		index++;                            // advance the index to get the next character
	}
	cout << '\n' << str << endl;

	/* 4. while loop with iterators */
	str = orig; // restore str to its original value

	auto beg = str.begin();

	while (beg != str.end() && !isspace(*beg))
    {
		*beg = toupper(*beg);
		beg++;
	}

	cout << '\n' << str << '\n' << endl;


	/** Range for loop to print the characters in str one character to a line **/
	str = orig; // restore str to its original value

	for (auto c : str)      // for every char in str
    {
        cout << c << endl;  // print the current character followed by a newline
    }


	/** Range for loop to change every character in str **/
	for (auto &c : str)  // note: c is a reference
    {
        c = '*';         // assign a new value to the underlying char in str
    }

	cout << '\n' << str << '\n' << endl;


	/** Traditional for loop with subscripts to print the characters in str one character to a line **/
	str = orig;  // restore str to its original value

	for (decltype(str.size()) ix = 0; ix != str.size(); ++ix)
    {
        cout << str[ix] << endl;    // print current character followed by a newline
    }


	/** Traditional for loop with subscripts to change every character in str **/
	for (decltype(str.size()) ix = 0; ix < str.size(); ix++)
    {
        str[ix] = '*';  // assigns a new value to the character in str
    }

	cout << '\n' << str << '\n' << endl;


	/** Traditional for loop with iterators to print the characters in str one character to a line **/
	str = orig;  // restore str to its original value

	for (auto beg = str.begin(); beg != str.end(); ++beg)
    {
        cout << *beg << endl;   // print current character followed by a newline
    }


	/** Traditional for loop with iterators to change every character in str **/
	for (auto beg = str.begin(); beg != str.end(); ++beg)
    {
        *beg = '*';     // assigns a new value to the character in str
    }

	cout << '\n' << str << '\n' << endl;

	return 0;
}