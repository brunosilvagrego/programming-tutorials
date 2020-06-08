#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    string s;
    string sought = "stop";

    while (cin >> s && s != sought)
        ;   // null statement

    cout << "String " << s << " found!" << endl;

    // NOTE: An empty block is equivalent to a null statement:
    while (cin >> s && s != sought)
    { }     // empty block

    // BEST PRACTICES: Null statements should be commented. That way anyone reading the code
    //                 can see that the statement was omitted intentionally.
    
    // WARNING: Extraneous null statements are not always harmless.

    ival = v1 + v2;;    // ok: second semicolon is a superfluous null statement
    
    // disaster: extra semicolon: loop body is this null statement
    while (iter != svec.end()) ;    // the while body is the empty statement
        ++iter;         // increment is not part of the loop

	return 0;
}