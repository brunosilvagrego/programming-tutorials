#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cctype>

using namespace std;

int main()
{
    // NOTE: C++ offers four jumps: break, continue, goto, and the return statement


    /** break **/

    // NOTE: A break statement terminates the nearest enclosing while, do while, for, or
    //       switch statement. Execution resumes at the statement immediately following the
    //       terminated statement.
    //
    //       A break can appear only within an iteration statement or switch statement
    //       (including inside statements or blocks nested inside such loops). A break affects only
    //       the nearest enclosing loop or switch

    string previousStr = "";
    string currentStr = "";
    unsigned cnt = 1;

    while (cin >> currentStr && currentStr != "$")
    {
        if (currentStr == previousStr)
        {
            ++cnt;
            break;  // breaks while loop
        }

        previousStr = currentStr;
    }

    if (cnt == 2)
    {
        cout << "String " << previousStr << " occurred " << cnt << " times in succession" << endl;
    }
    else if (cnt == 1)
    {
        cout << "No word was repeated!" << endl;
    }


    /** continue **/

    // NOTE: A continue statement terminates the current iteration of the nearest enclosing loop
    //       and immediately begins the next iteration. A continue can appear only inside a for,
    //       while, or do while loop, including inside statements or blocks nested inside such
    //       loops.
    //
    //       Like the break statement, a continue inside a nested loop affects only the
    //       nearest enclosing loop. Unlike a break, a continue may appear inside a switch
    //       only if that switch is embedded inside an iterative statement.

    previousStr = "";
    currentStr = "";
    cnt = 1;

    while (cin >> currentStr && currentStr != "$")
    {
        if (currentStr == previousStr)
        {
            if (!isupper(currentStr[0]))
            {
                continue;   // continues to next iteration
            }
            else
            {
                ++cnt;
                break;      // breaks while loop
            }
        }

        previousStr = currentStr;
    }

    if (cnt == 2)
    {
        cout << "String " << previousStr << " occurred " << cnt << " times in succession" << endl;
    }
    else if (cnt == 1)
    {
        cout << "No word was repeated!" << endl;
    }


    /** goto **/

    // NOTE: A goto statement provides an unconditional jump from the goto to a another statement in the same function.

    // BEST PRACTICES: Programs should not use gotos. gotos make programs hard to understand and hard to modify.

    unsigned i = 0;

Begin:
    if (i == 0)
    {
        goto Inc;
    }
    else
    {
        goto End;
    }

    i = 10;     // unreachable code

Inc:
    ++i;
    goto Begin;

End:
    cout << endl;
    cout << "i = " << i << endl;    // prints i = 1


    /** return **/

	return 0;
}