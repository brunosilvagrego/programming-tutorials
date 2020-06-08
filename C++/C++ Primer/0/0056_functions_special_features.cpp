#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;


/* ------------------------------------------------------------------------------------------------------------------- */
// NOTE: If a parameter has a default argument, all the parameters that follow it must also have default arguments.
//
//       Part of the work of designing a function with default arguments is ordering the
//       parameters so that those least likely to use a default value appear first and those
//       most likely to use a default appear last.
/* ------------------------------------------------------------------------------------------------------------------- */

typedef string::size_type sz;

// screen with 3 default parameters
string screen(sz ht = 24, sz wid = 80, char backgrnd = ' ')
{
    string temp = "ht = " + to_string(ht) + ", wid = " + to_string(wid) + ", background = " + backgrnd;

    return temp;
}

// NOTE: Each parameter can have its default specified only once in a given scope.
//       Any subsequent declaration can add a default only for a parameter that has not previously had a default specified.
//       Defaults can be specified only if all parameters to the right already have defaults.


/* --------------------------------------------------------------------------------------------------------------------- */

string screen(sz ht, sz wid, char backgrnd = ' ');
string screen(sz ht, sz wid, char backgrnd = '*');      // error: redeclaration
string screen(sz ht = 24, sz wid = 80, char backgrnd);  // ok: adds default

// the declarations of wd, def, and ht must appear outside a function
sz wd = 80;
char def = ' ';

sz ht();

string screen(sz = ht(), sz = wd, char = def);

string window = screen();   // calls screen(ht(), 80, ' ')

void f2()
{
    def = '*';          // changes the value of a default argument
    sz wd = 100;        // hides the outer definition of wd but does not change the default
    window = screen();  // calls screen(ht(), 80, '*')
}

/* --------------------------------------------------------------------------------------------------------------------- */

// BEST PRACTICES: Default arguments ordinarily should be specified with the function declaration in an appropriate header.


/* --------------------------------------------------------------------------------------------------------------------- */
// NOTE: The inline specification is only a request to the compiler. The compiler may choose to ignore this request.
//       In general, the inline mechanism is meant to optimize small, straight-line functions
//       that are called frequently. Many compilers will not inline a recursive function. A 75-line
//       function will almost surely not be expanded inline
/* --------------------------------------------------------------------------------------------------------------------- */

// inline version: find the shorter of two strings
inline const string &shorterString(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}

/* --------------------------------------------------------------------------------------------------------------------- */
// NOTE: A constexpr function is a function that can be used in a constant expression.
//       A constexpr function is defined like any other function but must meet certain
//       restrictions: The return type and the type of each parameter must be a literal
//       type, and the function body must contain exactly one return statement.
//
//       A constexpr function is not required to return a constant expression.
//
//       Put inline and constexpr Functions in Header Files.
//       Unlike other functions, inline and constexpr functions may be defined multiple
//       times in the program. After all, the compiler needs the definition, not just the
//       declaration, in order to expand the code. However, all of the definitions of a given
//       inline or constexpr must match exactly. As a result, inline and constexpr
//       functions normally are defined in headers.
/* --------------------------------------------------------------------------------------------------------------------- */

constexpr int new_sz() { return 42; }
constexpr int foo = new_sz();   // ok: foo is a constant expression

// scale(arg) is a constant expression if arg is a constant expression
constexpr size_t scale(size_t cnt) { return new_sz() * cnt; }
constexpr size_t foo2 = scale(2);

int arr[scale(2)];  // ok: scale(2) is a constant expression
int i = 2;          // i is not a constant expression
int a2[scale(i)];   // error: scale(i) is not a constant expression



int main()
{
    string window;

    /**** default parameters ****/

    /** screen(sz ht = 24, sz wid = 80, char backgrnd = ' ') **/
    window = screen();              // equivalent to screen(24,80,' ')
    cout << window << '\n' << endl;

    window = screen(66);            // equivalent to screen(66,80,' ')
    cout << window << '\n' << endl;

    window = screen(66, 256);       // screen(66,256,' ')
    cout << window << '\n' << endl;

    window = screen(66, 256, '#');  // screen(66,256,'#')
    cout << window << '\n' << endl;


    window = screen(, , '?');       // error: can omit only trailing arguments


    window = screen('?'); // calls screen('?',80,' ')
    cout << window << '\n' << endl;


    /**** inline ****/

    /** inline const string &shorterString(const string &s1, const string &s2) **/
    string s1("successes"), s2("failure");
	cout << shorterString(s1, s2) << endl;

	// call the size member of the string returned by shorterString
	cout << shorterString(s1, s2).size() << endl;

	// equivalent code as generated by the call to inline version
	// of shorterString
	cout << (s1.size() < s2.size() ? s1 : s2) << '\n' << endl;


	/**** constexpr ****/

    cout << "foo = " << foo << '\n' << endl;
    cout << "foo2 = " << foo2 << '\n' << endl;

	return 0;
}
