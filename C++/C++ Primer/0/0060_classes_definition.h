#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <string>
#include <iostream>


// NOTE: The only difference between using class and using struct to define a class is the default access level.
//       If we use the struct keyword, the members defined before the first access specifier are public.
//       If we use class, then the members are private.
//       As a matter of programming style, when we define a class intending for all of its members to be public,
//       we use struct. If we intend to have private members, then we use class.

class Sales_data
{
    // NOTE: Friends are not members of the class and are not affected by the access control of the section in which they are declared.
    //       A friend declaration only specifies access. It is not a general declaration of the function. If we want users of the class
    //       to be able to call a friend function, then we must also declare the function separately from the friend declaration.

    friend Sales_data add(const Sales_data&, const Sales_data&);
    friend std::ostream &print(std::ostream&, const Sales_data&);
    friend std::istream &read(std::istream&, Sales_data&);

public:

    // NOTE: Constructors have the same name as the class. Unlike other functions, constructors
    //       have no return type. Like other functions, constructors have a (possibly empty)
    //       parameter list and a (possibly empty) function body. A class can have multiple
    //       constructors. Like any other overloaded function, the constructors must
    //       differ from each other in the number or types of their parameters.~
    //
    //       Unlike other member functions, constructors may not be declared as const.
    //       When we create a const object of a class type, the object does not
    //       assume its “constness” until after the constructor completes the object’s initialization.
    //       Thus, constructors can write to const objects during their construction.

    /* Constructors */
    // Default constructor <=> Sales_data() = default; (if data members were default initialized below)
	Sales_data(): units_sold(0), revenue(0.0) { }

    // Constructor Initializer List
	Sales_data(const std::string &s): bookNo(s), units_sold(0), revenue(0.0) { }

    // Constructor Initializer List
	Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

    // Constructor outside the Class Body
	Sales_data(std::istream &);

    // NOTE: The compiler generates a default constructor automatically only if a class declares no constructors.
    
    // WARNING: Classes that have members of built-in or compound type usually should rely
    //          on the synthesized default constructor only if all such members have in-class initializers.

    // BEST PRACTICES: Constructors should not override in-class initializers except to use a different initial value.
    //                 If you can’t use in-class initializers, each constructor should explicitly initialize every member of built-in type.

    // WARNING: Classes that manage dynamic memory, generally cannot rely on the synthesized versions of Copy, Assignment
    //          and Destruction operations. However, it is worth noting that many classes that need dynamic memory can (and
    //          generally should) use a vector or a string to manage the necessary storage. Classes that use vectors and
    //          strings avoid the complexities involved in allocating and deallocating memory.


	// NOTE: The "this" parameter is defined for us implicitly. Indeed, it is illegal for us to define
    //       a parameter or variable named this. Inside the body of a member function, we can
    //       use this.
    //
    //       It would be legal, although unnecessary, to define isbn as
    //          std::string isbn() const { return this->bookNo; }
    //
    //       Because this is intended to always refer to “this” object, this is a const pointer.
    //       We cannot change the address that this holds.

    // NOTE: A const following the parameter list indicates that this is a pointer to const.
    //       Member functions that use const in this way are const member functions.

    // NOTE: The compiler processes classes in two steps: the member declarations are compiled
    //       first, after which the member function bodies, if any, are processed. Thus, member
    //       function bodies may use other members of their class regardless of where in the
    //       class those members appear

    // NOTE: Although every member must be declared inside its class, we can define a member
    //       function’s body either inside or outside of the class body.

	/* Operations on Sales_data objects - Member functions */
	std::string isbn() const
	{
	    return bookNo;
    }

	Sales_data& combine(const Sales_data&);

	double avg_price() const;


    /* Private data members */
private:
	std::string bookNo;
	unsigned units_sold;
	double revenue;

    // NOTE: The specified access level (public or private) remains in effect until the
    //       next access specifier or the end of the class body.
    //
    //       Encapsulation provides two important advantages:
    //       - User code cannot inadvertently corrupt the state of an encapsulated object.
    //       - The implementation of an encapsulated class can change over time without requiring changes in user-level code.
};


// NOTE: Ordinarily, nonmember functions that are part of the interface of a class
//       should be declared in the same header as the class itself.

/* Nonmember Sales_data interface functions */
Sales_data add(const Sales_data&, const Sales_data&);

std::ostream &print(std::ostream&, const Sales_data&);

std::istream &read(std::istream&, Sales_data&);

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
    return lhs.isbn() < rhs.isbn();
}

#endif
