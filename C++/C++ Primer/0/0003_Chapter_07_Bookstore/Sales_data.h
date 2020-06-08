/*
 * This file contains code from "C++ Primer, Fifth Edition", by Stanley B.
 * Lippman, Josee Lajoie, and Barbara E. Moo, and is covered under the
 * copyright and warranty notices given in that book:
 *
 * "Copyright (c) 2013 by Objectwrite, Inc., Josee Lajoie, and Barbara E. Moo."
 *
 *
 * "The authors and publisher have taken care in the preparation of this book,
 * but make no expressed or implied warranty of any kind and assume no
 * responsibility for errors or omissions. No liability is assumed for
 * incidental or consequential damages in connection with or arising out of the
 * use of the information or programs contained herein."
 *
 * Permission is granted for this code to be used for educational purposes in
 * association with the book, given proper citation if and when posted or
 * reproduced.Any commercial use of this code requires the explicit written
 * permission of the publisher, Addison-Wesley Professional, a division of
 * Pearson Education, Inc. Send your request for permission, stating clearly
 * what code you would like to use, and in what specific way, to the following
 * address:
 *
 * 	Pearson Education, Inc.
 * 	Rights and Permissions Department
 * 	One Lake Street
 * 	Upper Saddle River, NJ  07458
 * 	Fax: (201) 236-3290
*/

#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>

class Sales_data
{
    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:

    // NOTE: constructors using the synthesized version is safe only if we can also use in-class initializers
	Sales_data(): units_sold(0), revenue(0.0) { }

	Sales_data(const std::string &s): bookNo(s), units_sold(0), revenue(0.0) { }

	Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

	Sales_data(std::istream &);


	// NOTE: The this parameter is defined for us implicitly. Indeed, it is illegal for us to define
    //       a parameter or variable named this. Inside the body of a member function, we can
    //       use this.
    //
    //       It would be legal, although unnecessary, to define isbn as
    //          std::string isbn() const { return this->bookNo; }
    //
    //       Because this is intended to always refer to “this” object, this is a const pointer.
    //       We cannot change the address that this holds.

	/* Operations on Sales_data objects - Member functions */
	std::string isbn() const
	{
	    return bookNo;
    }

    // NOTE: A const following the parameter list indicates that this is a pointer to const.
    //       Member functions that use const in this way are const member functions.

    // NOTE: The compiler processes classes in two steps: the member declarations are compiled
    //       first, after which the member function bodies, if any, are processed. Thus, member
    //       function bodies may use other members of their class regardless of where in the
    //       class those members appear

	Sales_data& combine(const Sales_data&);

	double avg_price() const;

    // NOTE: Although every member must be declared inside its class, we can define a member
    //       function’s body either inside or outside of the class body.

private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;

};


// NOTE: Ordinarily, nonmember functions that are part of the interface of a class
//       should be declared in the same header as the class itself.

// Nonmember Sales_data interface functions
Sales_data add(const Sales_data&, const Sales_data&);

std::ostream &print(std::ostream&, const Sales_data&);

std::istream &read(std::istream&, Sales_data&);

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

#endif
