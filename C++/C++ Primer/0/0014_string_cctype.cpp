#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    /* Count the number of punctuation characters in s */
    string s("Hello World!!!");
	decltype(s.size()) punct_cnt = 0;   // punct_cnt has the same type that s.size returns

	cout << "s = " << s << endl;

    // The range for statement iterates through the elements in a given sequence and performs some operation on each value in that sequence.
    // for (declaration : expression)
    //          statement
    // where expression is an object of a type that represents a sequence,
    // and declaration defines the variable that we’ll use to access the underlying elements in the sequence.
    
	for (auto c : s)        // for every char in s
    {
        if (ispunct(c))     // if the character is punctuation
        {
            punct_cnt++;    // increment the punctuation counter
        }
    }

    cout << '\n' << "Count the number of punctuation characters in s" << endl;
	cout << "There are " << punct_cnt << " punctuation characters in \"" << s << "\"" << endl;


	/* Convert s to uppercase */
	string orig = s;

	// for every char in s (note: c is a reference)
	for (auto &c : s)
    {
		c = toupper(c);     // c is a reference, so this assignment changes the char in s
    }

    cout << '\n' << "Convert s to uppercase" << endl;
	cout << s << endl;


	/* Convert first word in s to uppercase */
	s = orig;  // restore s to original case
	decltype(s.size()) index = 0;

	// process characters in s until we run out of characters or we hit a whitespace
	while (index < s.size() && !isspace(s[index]))
    {
	    s[index] = toupper(s[index]);   // s[index] returns a reference so we can change the underlying character

		++index;    // increment the index to look at the next character on the next iteration
	}

	cout << '\n' << "Convert first word in s to uppercase" << endl;
	cout << s << endl;


	/* Print the first character in str */
	string str("some string");
	orig = str;

	cout << '\n' << "str = " << str << endl;

	if (!str.empty())   // make sure there's a character to print
    {
        cout << '\n' << "Print the first character in str" << endl;
        cout << str[0] << endl;     // print the first character in str
    }


    /* Assign a new value to the first character in str */
	if (!str.empty())   // make sure there's a character in str[0]
    {
        str[0] = toupper(str[0]);

        cout << '\n' << "Assign a new value to the first character in str" << endl;
        cout << str << endl;
    }


    /* Using a Subscript for Random Access */
    const string hexdigits = "0123456789ABCDEF";    // possible hex digits
    string result;          // will hold the resulting hexify'd string
    string::size_type n;    // hold numbers from the input

    cout << '\n' << "Enter a series of numbers between 0 and 15 separated by spaces. Hit ENTER when finished: " << endl;

    while (cin >> n)
    {
        if (n < hexdigits.size())   // ignore invalid input
        {
            result += hexdigits[n]; // fetch the indicated hex digit
        }
    }

    cout << "Your hex number is: " << result << endl;

	return 0;
}