#include <iostream>
#include <exception>

using namespace std;

// Exception Handling:
//      throw => A program throws an exception when a problem shows up. This is done using a throw keyword.
//
//      catch => A program catches an exception with an exception handler at the place in a program where you
//               want to handle the problem.
//
//      try   => A try block identifies a block of code for which particular exceptions will be activated.
//               It's followed by one or more catch blocks.
//
//      Syntax:
/*
try
{
    // protected code
}
catch( ExceptionName e1 )
{
    // catch block
}
catch( ExceptionName e2 )
{
    // catch block
} catch( ExceptionName eN )
{
    // catch block
}
*/


double division (int a, int b)
{
    double div;

    if (b == 0)
    {
        throw "Division by zero condition!";
    }

    div = (double) a / b;

    return div;
}


// NOTE: You can define your own exceptions by inheriting and overriding exception class functionality.
//       Here, what() is a public method provided by exception class and it has been overridden by all the
//       child exception classes. This returns the cause of an exception.

struct MyException : public exception
{
    const char * what () const throw ()
    {
        return "C++ Exception";
    }
};


int main ()
{
    int x = 50;
    int y = 3;
    double z = 0;

    /* No Exception */
    try
    {
        z = division(x, y);
        cout << x << " / " << y << " = " << z << endl;
    }
    catch (const char* msg)
    {
        cerr << msg << endl;
    }

    cout << endl;

    /* Exception */
    y = 0;

    try
    {
        z = division(x, y);
        cout << x << " / " << y << " = " << z << endl;
    }
    catch (const char* msg)
    {
        cout << x << " / " << y << " = error -> ";

        cerr << msg << endl;
    }

    cout << endl;

    /* My Exception */
    try
    {
        if (y == 0)
        {
            throw MyException();
        }
    }
    catch (MyException& e)
    {
        cout << "MyException caught: " << e.what() << endl;
    }
    catch (exception& e)
    {
        //Other errors
    }


    return 0;
}
