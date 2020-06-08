#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int>::iterator it1;          // it1 can read and write vector<int> elements
    string::iterator it2;               // it2 can read and write characters in a string
    vector<int>::const_iterator it3;    // it3 can read but not write elements
    string::const_iterator it4;         // it4 can read but not write characters

    vector<int> v;
    const vector<int> cv;
    auto it5 = v.begin();               // it5 has type vector<int>::iterator
    auto it6 = cv.begin();              // it6 has type vector<int>::const_iterator
    auto it7 = v.cbegin();              // it7 has type vector<int>::const_iterator

    (*it).empty();  // dereferences it and calls the member empty on the resulting object
    it->empty();    // equivalent to (*it).empty()
    *it.empty();    // error: attempts to fetch the member named empty from it but it is an iterator and has no member named empty

	return 0;
}