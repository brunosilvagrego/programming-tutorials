#include <iostream>
#include "Sales_item.h"

int main()
{
    Sales_item total;   // variable to hold data for the next transaction

    // read the first transaction and ensure that there are data to process
    if (std::cin >> total)
    {
		Sales_item trans;   // variable to hold the running sum

        // read and process the remaining transactions
        while (std::cin >> trans)
        {
			// if we're still processing the same book
            if (total.isbn() == trans.isbn())
            {
                total += trans; // update the running total
            }
            // print results for the previous book
            else
            {
                std::cout << total << std::endl;
                total = trans;  // total now refers to the next book
            }
		}
        std::cout << total << std::endl;    // print the last transaction
    }
    // no input! warn the user
    else
    {
        std::cerr << "No data?!" << std::endl;
        return -1;  // indicate failure
    }

    return 0;
}
