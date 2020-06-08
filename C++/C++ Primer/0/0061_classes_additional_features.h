#include <string>
#include <iostream>

class Screen
{
    // NOTE: A class can also make another class its friend or it can declare specific
    //       member functions of another (previously defined) class as friends. In addition, a friend
    //       function can be defined inside the class body. Such functions are implicitly inline.
    //
    //       The member functions of a friend class can access all the members, including the
    //       nonpublic members, of the class granting friendship.
    //
    //       Friendship is not transitive. That is, if class Window_mgr has its own friends, those friends have
    //       no special access to Screen. Each class controls which classes or functions are its friends.

    friend class Window_mgr;

    // Screen can instead specify that only the clear member is allowed access.
    // Window_mgr::clear must have been declared before class Screen
    friend void Window_mgr::clear(ScreenIndex);

public:
    typedef std::string::size_type pos;
    // alternative way to declare a type member using a type alias
    // using pos = std::string::size_type;

    /* Constructors */
    // Default constructor declaration needed because Screen has another constructor
	Screen() = default;
	// Screen(): cursor(0), height(0), width(0) { } <=> Screen() = default;

	// cursor initialized to 0 by its in-class initializer
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c) { }

    // Constructor Initializer List
    Screen(pos ht = 0, pos wd = 0): cursor(0), height(ht), width(wd), contents(ht * wd, ' ') { }


    /* Member functions */
    // Get the character at the cursor
    char get() const
    {
        return contents[cursor];            // implicitly inline
    }

    // Overloaded member function
    inline char get(pos ht, pos wd) const;  // explicitly inline

	Screen &clear(char = bkground);

private:
	static const char bkground = ' ';

public:
    Screen &move(pos r, pos c);             // can be made inline later

    // Set the character at the cursor
    Screen &set(char);
    // Overloaded member function
    Screen &set(pos, pos, char);

    // display overloaded on whether the object is const or not
    Screen &display(std::ostream &os)
    {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const
    {
        do_display(os);
        return *this;
    }

private:
    // function to do the work of displaying a Screen
    void do_display(std::ostream &os) const
    {
         os << contents;
    }

    // ADVICE: Use Private Utility Functions for Common Code. We do so for several reasons:
    //         - A general desire to avoid writing the same code in more than one place.
    //
    //         - We expect that the display operation will become more complicated as our class evolves.
    //           As the actions involved become more complicated, it makes more obvious sense to write
    //           those actions in one place, not two.
    //
    //         - It is likely that we might want to add debugging information to do_display during development
    //           that would be eliminated in the final product version of the code. It will be easier to do so
    //           if only one definition of do_display needs to be changed to add or remove the debugging code.
    //
    //         - There needn’t be any overhead involved in this extra function call. We defined do_display inside
    //           the class body, so it is implicitly inline. Thus, there likely be no run-time overhead associating with calling do_display.
    //
    //         - In practice, well-designed C++ programs tend to have lots of small functions such as do_display
    //           that are called to do the “real” work of some other set of functions.

	/* Private data members */
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;

public:
    void some_member() const;

private:
    mutable size_t access_ctr;  // may change even in a const object
};


// NOTE: A mutable data member is never const, even when it is a member of a const
//       object. Accordingly, a const member function may change a mutable member.
void Screen::some_member() const
{
    ++access_ctr;   // keep a count of the calls to any member function
                    // whatever other work this member needs to do
}

/* Member functions body */
Screen &Screen::clear(char c)
{
	contents = std::string(height*width, c);
	return *this;
}

// we can specify inline on the definition
inline Screen &Screen::move(pos r, pos c)
{
    pos row = r * width;        // compute the row location
    cursor = row + c;           // move cursor to the column within that row
    return *this;               // return this object as an lvalue
}

// declared as inline in the class
char Screen::get(pos r, pos c) const
{
    pos row = r * width;        // compute row location
    return contents[row + c];   // return character at the given column
}

inline Screen &Screen::set(char c)
{
    contents[cursor] = c;       // set the new value at the current cursor location
    return *this;               // return this object as an lvalue
}

inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;   // set specified location to given value
	return *this;                   // return this object as an lvalue
}


/** Classes Additional Features **/

// NOTE: Even if two classes have exactly the same member list, they are different types.
//       The members of each class are distinct from the members of any other class (or any other scope).

struct First
{
    int memi;
    int getMem();
};

struct Second
{
    int memi;
    int getMem();
};

First obj1;
Second obj2 = obj1; // error: obj1 and obj2 have different types


// Class declarations
Sales_data item1;       // default-initialized object of type Sales_data
class Sales_data item1; // equivalent declaration


// NOTE: A class is considered declared (but not yet defined) as soon as its class name has been seen.
//       Therefore, a class can have data members that are pointers or references to its own type.

class Link_screen
{
    Screen window;
    Link_screen *next;
    Link_screen *prev;
};