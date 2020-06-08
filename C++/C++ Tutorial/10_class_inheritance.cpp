#include <iostream>

using namespace std;

// NOTE: When creating a class, instead of writing completely new data members and member functions, the programmer
//       can designate that the new class should inherit the members of an existing class. This existing class is
//       called the base class, and the new class is referred to as the derived class.

// Base class
class Shape
{
    public:
        void setWidth (int w) { width = w; }
        void setHeight (int h) { height = h; }

    protected:
        int width;
        int height;
};

// Base class
class PaintCost
{
    public:
        int getCost (int area) { return area * 70; }
};

// Derived class => Multiple Inheritance
class Rectangle: public Shape, public PaintCost
{
    public:
        int getArea() { return (width * height); }
};


int main (void)
{
    int area;
    Rectangle Rect;

    // Object definition
    Rect.setWidth(5);
    Rect.setHeight(7);

    area = Rect.getArea();

    // Print the area of the object
    cout << "Rectangle area = " << Rect.getArea() << endl;

    // Print the total cost of painting
    cout << "Total paint cost: $" << Rect.getCost(area) << endl;

    return 0;
}
