#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;


// NOTE: A template is a blueprint or formula for creating a generic class or a function. The library
//       containers like iterators and algorithms are examples of generic programming and have been
//       developed using the template concept.
//
//       There is a single definition of each container, but we can define many different kinds of vectors.
//       For example: vector <int> or vector <string>.


// Function Template
template <typename T>
inline T const& Max (T const& a, T const& b) { return (a < b ? b : a); }

// Class Template
template <class T>
class Stack
{
    private:
        vector<T> elems;        // Vector elements

    public:
        void push(T const&);    // Push element
        void pop();             // pop element
        T top() const;          // return top element

        bool empty() const { return elems.empty(); }    // Return true if empty.
};

template <class T>
void Stack<T>::push (T const& elem)
{
    // Append copy of passed element
    elems.push_back(elem);
}

template <class T>
void Stack<T>::pop ()
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::pop(): empty stack");
    }

    // Remove last element
    elems.pop_back();
}

template <class T>
T Stack<T>::top () const
{
    if (elems.empty())
    {
        throw out_of_range("Stack<>::top(): empty stack");
    }

    // Return copy of last element
    return elems.back();
}


int main ()
{
    // Max(int, int)
    int i = 39;
    int j = 20;
    cout << "Max(i, j): " << Max(i, j) << "\n" << endl;

    // Max(double, double)
    double f1 = 13.5;
    double f2 = 20.7;
    cout << "Max(f1, f2): " << Max(f1, f2) << "\n" << endl;

    // Max(string, string)
    string s1 = "Hello";
    string s2 = "World";
    cout << "Max(s1, s2): " << Max(s1, s2) << "\n" << endl;

    // Classes Stack<int> and Stack<string>
    Stack<int> intStack;        // Stack of ints
    Stack<string> stringStack;  // Stack of strings


    // intStack.top()
    try
    {
        cout << "intStack.top() = " << intStack.top() << "\n" << endl;
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    // intStack.pop()
    try
    {
        intStack.pop();
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    // intStack.top()
    try
    {
        cout << "intStack.top() = " << intStack.top() << "\n" << endl;
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    // intStack.pop()
    try
    {
        intStack.pop();
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    // intStack .push(), .top(), .pop()
    try
    {
        intStack.push(7);
        cout << "intStack.push(7)" << endl;
        cout << "intStack.top() = " << intStack.top() << "\n" << endl;

        intStack.push(10);
        cout << "intStack.push(10)" << endl;
        cout << "intStack.top() = " << intStack.top() << "\n" << endl;

        intStack.pop();
        cout << "intStack.pop()" << endl;
        cout << "intStack.top() = " << intStack.top() << "\n" << endl;
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    // stringStack .push(), .top(), .pop()
    try
    {
        stringStack.push("hello");
        cout << "stringStack.push(\"hello\")" << endl;
        cout << "stringStack.top() = " << stringStack.top() << "\n" << endl;

        stringStack.push("world");
        cout << "stringStack.push(\"world\")" << endl;
        cout << "stringStack.top() = " << stringStack.top() << "\n" << endl;

        stringStack.pop();
        cout << "stringStack.pop()" << endl;
        cout << "stringStack.top() = " << stringStack.top() << "\n" << endl;
    }
    catch (exception const& ex)
    {
        cerr << "Exception: " << ex.what() << "\n" << endl;
    }

    return 0;
}
