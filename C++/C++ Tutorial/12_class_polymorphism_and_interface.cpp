#include <iostream>

using namespace std;

// NOTE: The purpose of an Abstract Class (ABC) is to provide an appropriate base class from which other classes
//       can inherit. Abstract classes cannot be used to instantiate objects and serve only as an interface.
//       Attempting to instantiate an object of an abstract class causes a compilation error.
//
//       If a subclass of an ABC needs to be instantiated, it has to implement each of the virtual functions,
//       which means that it supports the interface declared by the ABC. Failure to override a pure virtual
//       function in a derived class causes a compilation error when attempting to instantiate objects of that class.
//       Classes that can be used to instantiate objects are called concrete classes.

// Abstract Class (ABC)
class Shape
{
    protected:
        int width;
        int height;

    public:
        Shape(int a = 0, int b = 0)
        {
            width = a;
            height = b;
        }

        // NOTE: "= 0" tells the compiler that the function has no body.
        // Pure virtual function
        virtual int area() = 0;
};

// Derived class => concrete class
class Rectangle: public Shape
{
    public:
        Rectangle (int a = 0, int b = 0) : Shape(a, b) { }

        int area () { return (width * height); }
};

// Derived class => concrete class
class Triangle: public Shape
{
    public:
        Triangle (int a = 0, int b = 0) : Shape(a, b) { }

        int area () { return (width * height / 2); }
};

// NOTE: Each of the child classes has a separate implementation for the function area(). This is how
//       polymorphism is generally used. You have different classes with a function of the same name, and
//       even the same parameters, but with different implementations.


int main ()
{
    /* Shape Rectangle */
    Rectangle rec(10, 7);
    cout << "Rectangle Area = " << rec.area() << endl;

    /* Shape Triangle */
    Triangle  tri(10, 5);
    cout << "Triangle Area  = " << tri.area() << endl;

    return 0;
}


// NOTE: An object-oriented system might use an abstract base class to provide a common and standardized interface
//       appropriate for all the external applications. Then, through inheritance from that abstract base class,
//       derived classes are created that operate similarly.
//
//       This architecture also allows new applications to be added to a system easily, even after the system has
//       been defined.