#include <iostream>
#include <string>
#include <iterator>
#include <vector>

#include "Sales_data.h"

using namespace std;


int main()
{
    /** Add Items **/

    /* Data: 0-201-78345-X 3 20.00   0-201-78345-X 2 25.00 */

    Sales_data data1, data2;

    // Note: Objects that are const, and references or pointers to const objects,
    //       may call only const member functions.

	if (read(cin, data1) && read(cin, data2))   // read the transactions
    {
		if (data1.isbn() == data2.isbn())       // check isbns
		{
			data1.combine(data2);               // add the transactions
			cout << '\n' << "Total:" << endl;
			print(cout, data1);                 // print the results
			cout << endl;                       // followed by a newline
		}
	}
	else
    {
        cerr << "Input failed!" << endl;
    }

    cout << endl;

    /** Average Price **/

    /* Data: 0-201-70353-X 4 24.99
             0-201-82470-1 4 45.39
             0-201-88954-4 2 15.00
             0-201-88954-4 5 12.00
             0-201-88954-4 7 12.00
             0-201-88954-4 2 12.00
             0-399-82477-1 2 45.39
             0-399-82477-1 3 45.39
             0-201-78345-X 3 20.00
             0-201-78345-X 2 25.00
    */

    Sales_data total;       // variable to hold the running sum

	if (read(cin, total))   // read the first transaction
    {
		Sales_data trans;   // variable to hold data for the next transaction

		while(read(cin, trans))                 // read the remaining transactions
		{
			if (total.isbn() == trans.isbn())   // check the isbns
            {
				total.combine(trans);           // update the running total
            }
			else
            {
                cout << '\n' << "Total:" << endl;
				print(cout, total) << '\n' << endl; // print the results

				total = trans;  // process the next book
				// default assignment for Sales_data is equivalent to:
                // total.bookNo = trans.bookNo;
                // total.units_sold = trans.units_sold;
                // total.revenue = trans.revenue;
			}
		}

		cout << '\n' << "Total:" << endl;
		print(cout, total) << '\n' << endl;             // print the last transaction
	}
	else                                        // there was no input
    {
		cerr << "No data?!" << endl;            // notify the user
	}

    return 0;
}
