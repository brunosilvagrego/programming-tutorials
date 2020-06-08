#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <cstddef>


using namespace std;

int main()
{
    string s1 = "a string";
    string *p = &s1;

    auto n1 = s1.size();    // run the size member of the string s1
    auto n2 = (*p).size();  // run size on the object to which p points
    auto n3 = p->size();    // equivalent to (*p).size()

    cout << n1 << " " << n2 << " " << n3 << endl;
    cout << endl;

    // Because dereference has a lower precedence than dot, we must parenthesize the dereference subexpression
    // Run the size member of p, then dereference the result!
    *p.size();              // error: p is a pointer and has no member named size

    vector <string> svec = {"Hello", "My", "Beautiful", "World"};
    auto iter = svec.begin();
    string str;

    str = *iter++;
    cout << str << endl;
    cout << endl;

    for (auto it = str.begin(); it != str.end(); ++it)
    {
        cout << *it << endl;
    }

    cout << endl;

    for (auto c : str)      // for every char in str
    {
        cout << c << endl;  // print the current character followed by a newline
    }

    cout << endl;

    if(!iter->empty())
    {
        str = *iter;

        cout << str << endl;
    }

    cout << endl;

    if (!iter++->empty())
    {
        str = *iter;

        cout << str << endl;
    }

    cout << endl;

    str = *++iter;
    cout << str << endl;
    cout << endl;

    str = (*iter)++;        // error: no 'operator++(int)'
    str = *iter.empty()     // error: no member empty()
    str = ++*iter;          // error: no match for 'operator++'

	return 0;
}