/* String Initialization */
string foo = "Hello World!";    // define and initialize
string bar;                     // default initialized to the empty string
bar = "Hello World!";           // assign a new value to bar


/* Class Initialization */
// legal but sloppier way to write the Sales_data constructor: no constructor initializers
Sales_data::Sales_data(const string &s, unsigned cnt, double price)
{
    bookNo = s;
    units_sold = cnt;
    revenue = cnt * price;
}


/* Default constructors */
class_name( ) ;
class_name :: class_name( ) { }
class_name() = delete;                      // since C++ 11
class_name() = default;                     // since C++11
class_name :: class_name( ) = default;     // since C++11

// NOTE: A default constructor is a constructor which can be called with no arguments (either defined with an empty
//       parameter list, or with default arguments provided for every parameter). A type with a public default
//       constructor is DefaultConstructible.

// WARNING: It is a common mistake among programmers new to C++ to try to declare an object initialized with the default constructor.
Sales_data obj();   // oops! declares a function, not an object
Sales_data obj2;    // ok: obj2 is an object, not a function; calls default constructor


/* Constructor Initializers Are Sometimes Required */
class ConstRef
{
public:
    ConstRef(int ii);
private:
    int i;
    const int ci;
    int &ri;
};

// error: ci and ri must be initialized
ConstRef::ConstRef(int ii)
{
    // assignments:
    i = ii; // ok
    ci = ii; // error: cannot assign to a const
    ri = i; // error: ri was never initialized
}

// ok: explicitly initialize reference and const members
ConstRef::ConstRef(int ii): i(ii), ci(ii), ri(i) { }

// NOTE:  We must use the constructor initializer list to provide values for members that are const, reference,
//        or of a class type that does not have a default constructor.

// ADVICE: Use Constructor Initializers. In many classes, the distinction between initialization and assignment is
//         strictly a matter of low-level efficiency: A data member is initialized and then assigned when it could
//         have been initialized directly. More important than the efficiency issue is the fact that some data
//         members must be initialized. By routinely using constructor initializers, you can avoid being surprised
//         by compile-time errors when you have a class with a member that requires a constructor initializer.


/* Order of Member Initialization */
class X
{
    int i;
    int j;
public:
    // undefined: i is initialized before j
    X(int val): j(val), i(j) { }

    // NOTE: In this case, the constructor initializer makes it appear as if j is initialized with val
    // and then j is used to initialize i. However, i is initialized first. The effect of this initializer
    // is to initialize i with the undefined value of j!

    // In this version, the order in which i and j are initialized doesn’t matter.
    X(int val): i(val), j(val) { }
};

// BEST PRACTICES: It is a good idea to write constructor initializers in the same order as the members are declared.
//                 Moreover, when possible, avoid using members to initialize other members.


/* Default Arguments and Constructors */
class Sales_data
{
public:
    // defines the default constructor as well as one that takes a string argument
    Sales_data(std::string s = ""): bookNo(s) { }
    
    // remaining constructors unchanged
    Sales_data(std::string s, unsigned cnt, double rev): bookNo(s), units_sold(cnt), revenue(rev*cnt) { }

    Sales_data(std::istream &is) { read(is, *this); }
};

// NOTE: A constructor that supplies default arguments for all its parameters also defines the default constructor.


/* Delegating Constructors */
class Sales_data
{
public:
    // nondelegating constructor initializes members from corresponding arguments
    Sales_data(std::string s, unsigned cnt, double price): bookNo(s), units_sold(cnt), revenue(cnt*price) { }

    // remaining constructors all delegate to another constructor
    Sales_data(): Sales_data("", 0, 0) {}

    Sales_data(std::string s): Sales_data(s, 0,0) {}

    Sales_data(std::istream &is): Sales_data() { read(is, *this); }
};

// NOTE: When a constructor delegates to another constructor, the constructor initializer list and function body
//       of the delegated-to constructor are both executed. In Sales_data, the function bodies of the delegated-to
//       constructors happen to be empty. Had the function bodies contained code, that code would be run before control
//       returned to the function body of the delegating constructor.

// BEST PRACTICES: In practice, it is almost always right to provide a default constructor if other constructors are being defined.


/* Implicit Class-Type Conversions */
string null_book = "9-999-99999-9";

// constructs a temporary Sales_data object with units_sold and revenue equal to 0 and bookNo equal to null_book
item.combine(null_book);

// error: requires two user-defined conversions:
// (1) convert "9-999-99999-9" to string
// (2) convert that (temporary) string to Sales_data
item.combine("9-999-99999-9");

// ok: explicit conversion to string, implicit conversion to Sales_data
item.combine(string("9-999-99999-9"));

// ok: implicit conversion to string, explicit conversion to Sales_data
item.combine(Sales_data("9-999-99999-9"));


/* Suppressing Implicit Conversions Defined by Constructors */
class Sales_data
{
public:
    Sales_data() = default;

    Sales_data(const std::string &s, unsigned n, double p): bookNo(s), units_sold(n), revenue(p*n) { }

    explicit Sales_data(const std::string &s): bookNo(s) { }

    explicit Sales_data(std::istream&);
};

// NOTE: The explicit keyword is meaningful only on constructors that can be called with a single argument.
//       Constructors that require more arguments are not used to perform an implicit conversion, so there
//       is no need to designate such constructors as explicit. The explicit keyword is used only on the
//       constructor declaration inside the class. It is not repeated on a definition made outside the class body.

// error: explicit allowed only on a constructor declaration in a class header
explicit Sales_data::Sales_data(istream& is)
{
    read(is, *this);
}

// NOTE: When a constructor is declared explicit, it can be used only with the direct form of initialization.
//       Moroever, the compiler will not use this constructor in an automatic conversion.

// ok: direct initialization
Sales_data item1 (null_book);

// error: cannot use the copy form of initialization with an explicit constructor
Sales_data item2 = null_book;

// ok: the argument is an explicitly constructed Sales_data object
item.combine(Sales_data(null_book));

// ok: static_cast can use an explicit constructor
item.combine(static_cast<Sales_data>(cin));


/* Aggregate Classes */

// NOTE: An aggregate class gives users direct access to its members and has special initialization syntax. A class is an aggregate if:
//       - All of its data members are public.
//       - It does not define any constructors.
//       - It has no in-class initializers.
//       - It has no base classes or virtual functions.

struct Data
{
    int ival;
    string s;
};

// val1.ival = 0; val1.s = string("Anna")
Data val1 = { 0, "Anna" };

// error: can't use "Anna" to initialize ival, or 1024 to initialize s
Data val2 = { "Anna", 1024 };


/* Literal Classes */

// NOTE: An aggregate class whose data members are all of literal type is a literal class.
//       A nonaggregate class, that meets the following restrictions, is also a literal class:
//       - The data members all must have literal type.
//       - The class must have at least one constexpr constructor.
//       - If a data member has an in-class initializer, the initializer for a member of builtin
//         type must be a constant expression, or if the member has class type, the initializer
//         must use the member’s own constexpr constructor.
//       - The class must use default definition for its destructor, which is the member that
//         destroys objects of the class type.

class Debug
{
public:
    constexpr Debug(bool b = true): hw(b), io(b), other(b) { }

    constexpr Debug(bool h, bool i, bool o): hw(h), io(i), other(o) { }

    constexpr bool any() { return hw || io || other; }

    void set_io(bool b) { io = b; }

    void set_hw(bool b) { hw = b; }
    
    void set_other(bool b) { hw = b; }

private:
    bool hw;    // hardware errors other than IO errors
    bool io;    // IO errors
    bool other; // other errors
};
