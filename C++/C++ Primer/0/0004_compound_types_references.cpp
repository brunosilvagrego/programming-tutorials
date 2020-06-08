#include <iostream>

using namespace std;

int main()
{
    int ival = 1024;
    int &refVal = ival; // refVal refers to (is another name for) ival

    cout << "refVal = " << refVal << endl;

    refVal = 2; // assigns 2 to the object to which refVal refers, i.e., to ival

    cout << "ival = " << ival << endl;

    // ok: refVal3 is bound to the object to which refVal is bound, i.e., to ival
    int &refVal3 = refVal;

    cout << "refVal3 = " << refVal3 << endl;

    // initializes i from the value in the object to which refVal is bound
    int i = refVal; // ok: initializes i to the same value as ival

    cout << "i = " << i << endl;

    return 0;
}

