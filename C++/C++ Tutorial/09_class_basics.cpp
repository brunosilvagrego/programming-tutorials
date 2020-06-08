#include <iostream>

using namespace std;

// Class Members Access Specifier:
//
// public    - Members are accessible from anywhere outside the class but within the program.
//
// private   - Members cannot be accessed, or even viewed from outside the class. Only the class and
//             friend functions can access private members.
//
// protected - Members can be accessed in derived classes, but not in other outside scopes.
//
// NOTE: Each section remains in effect until either another section label or the closing right brace of
//       the class body is seen. The default access for members and classes is private.


class Box
{
    private:
        // Member variables
        double length;
        double width;
        double height;

    public:
        // NOTE:  When we declare a member of a class as static it means no matter how many objects of the
        //        class are created, there is only one copy of the static member.
        static int boxCount;

        // NOTE:  By declaring a function member as static, you make it independent of any particular object of the class.
        //        A static member function can be called even if no objects of the class exist.
        //        A static member function can only access static data members, other static member functions and any other
        //        functions from outside the class.
        static int getBoxCount() { return boxCount; }

        // Member functions declaration
        Box ();                             // Default constructor
        Box (double l, double w, double h); // Constructor with parameters
        Box (const Box &box);               // Copy constructor

        ~Box();                             // Destructor

        void setLength (double l);
        void setWidth (double w);
        void setHeight (double h);

        double getVolume (void);

        // Inline functions
        inline double getLength (void) { return length; }
        inline double getWidth (void)  { return width;  }
        // NOTE: A function definition within a class is an inline function, even without the use of the inline specifier.
        double getHeight (void) { return height; }

        int compare (Box &box) { return (this->getVolume() > box.getVolume()); }

        friend void printSpecs (Box &box);
};

// Initialize static member of class Box
int Box::boxCount = 0;

/* Member functions definitions */
// Default constructor
Box::Box (void)
{
    setLength(0);
    setWidth(0);
    setHeight(0);

    boxCount++;

    cout << "The Box object was created by the default constructor" << endl;
}

// Constructor with parameters
Box::Box (double l, double w, double h)
{
    setLength(l);
    setWidth(w);
    setHeight(h);

    boxCount++;

    cout << "The Box object was created by the constructor with parameters" << endl;
}

// Copy constructor
Box::Box (const Box &box)
{
    setLength(box.length);
    setWidth(box.width);
    setHeight(box.height);

    boxCount++;

    cout << "The Box object was created by the copy constructor" << endl;
}

// Destructor
Box::~Box (void)
{
    cout << "The Box object was deleted" << endl;
}

double Box::getVolume (void)
{
    return length * width * height;
}

void Box::setLength (double l)
{
    length = l;
}

void Box::setWidth (double w)
{
    width = w;
}

void Box::setHeight (double h)
{
    height = h;
}

// NOTE: printSpecs() is not a member function of any class.
//       Because printSpecs() is a friend of class Box, it can directly access any member of this class.
void printSpecs (Box &box)
{
    cout << "Box length = " << box.length << endl;
    cout << "Box width  = " << box.width << endl;
    cout << "Box height = " << box.height << endl;
}


int main()
{
    // Print total number of objects before creating any object
    cout << "Total Boxes = " << Box::getBoxCount() << "\n" << endl;

    // Box 1 definition
    Box Box1;                   // Default constructor

    cout << "Volume of Box1 = " << Box1.getVolume() << endl;

    Box1.setLength(6.1);
    Box1.setWidth(7.2);
    Box1.setHeight(5.3);

    // Box1 Specs
    cout << "Box1 Specs:" << endl;
    printSpecs(Box1);
    cout << "Volume of Box1 = " << Box1.getVolume() << "\n" << endl;


    // Box 2 definition
    Box Box2(12.0, 13.0, 14.0); // Constructor with parameters

    // Box2 Specs
    cout << "Box2 Specs:" << endl;
    cout << "Box length = " << Box2.getLength() << endl;
    cout << "Box width  = " << Box2.getWidth() << endl;
    cout << "Box height = " << Box2.getHeight() << endl;
    cout << "Volume of Box2 = " << Box2.getVolume() << "\n" << endl;


    // Boxes comparison
    if (Box1.compare(Box2))
    {
        cout << "Box2 is smaller than Box1.\n" << endl;
    }
    else
    {
        cout << "Box2 is larger than Box1.\n" << endl;
    }


    // Box 3 specification
    Box Box3 = Box1;            // Copy Constructor

    // Box3 Specs
    cout << "Box3 Specs:" << endl;
    printSpecs(Box3);
    cout << "Volume of Box3 = " << Box3.getVolume() << "\n" << endl;


    // Box4 definition
    Box Box4(2.0, 3.0, 4.0);

    // Pointer to the class Box
    Box *ptrBox = &Box4;

    // Box4 Specs
    cout << "Box4 Specs:" << endl;
    printSpecs(Box4);
    cout << "Volume of Box4: " << ptrBox->getVolume() << "\n" << endl;


    // Print total number of Box objects created
    cout << "Total Boxes = " << Box::boxCount << "\n" << endl;


    return 0;
}
