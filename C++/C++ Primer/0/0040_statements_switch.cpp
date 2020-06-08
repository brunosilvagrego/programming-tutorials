#include <iostream>
#include <string>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    // BEST PRACTICES:
    //
    // Omitting a break at the end of a case happens rarely. If you do omit a
    // break, include a comment explaining the logic.
    //
    // Although it is not necessary to include a break after the last label of a
    // switch, the safest course is to provide one. That way, if an additional case
    // is added later, the break is already in place.
    //
    // It can be useful to define a default label even if there is no work for the
    // default case. Defining an empty default section indicates to subsequent
    // readers that the case was considered.
    
    // initialize counters for each vowel
    unsigned aCnt = 0, eCnt = 0, iCnt = 0, oCnt = 0, uCnt = 0;
    char ch;

    while (cin >> ch && ch != '$')
    {
    	// if ch is a vowel, increment the appropriate counter
    	switch (ch)
    	{
    		case 'a':
    			++aCnt;
    			break;
    		case 'e':
    			++eCnt;
    			break;
    		case 'i':
    			++iCnt;
    			break;
    		case 'o':
    			++oCnt;
    			break;
    		case 'u':
    			++uCnt;
    			break;
    	}
    }

    // print results
    cout << "Number of vowel a: \t" << aCnt << '\n'
         << "Number of vowel e: \t" << eCnt << '\n'
         << "Number of vowel i: \t" << iCnt << '\n'
         << "Number of vowel o: \t" << oCnt << '\n'
         << "Number of vowel u: \t" << uCnt << '\n' << endl;

    // initialize counters for each vowel
    unsigned vowelCnt = 0;
    unsigned otherCnt = 0;  // count anything that isn't a vowel

    while (cin >> ch && ch != '$')
    {
        // if ch is a vowel, increment the appropriate counter
        switch (ch)
        {
			case 'a': case 'e': case 'i': case 'o': case 'u':
				++vowelCnt;
				break;
            default:
                ++otherCnt;
                break;
        }
    }

    // print results
    cout << "Number of vowels: \t" << vowelCnt << '\n'
         << "Total non-vowels: \t" << otherCnt << '\n';

	return 0;
}