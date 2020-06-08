#include <iostream>
#include <string>

using namespace std;

// NOTE: An overloaded declaration is a declaration that is declared with the same name as a previously declaration
//       in the same scope, except that both declarations have different arguments and different implementations.
//
//       When you call an overloaded function or operator, the compiler determines the most appropriate definition
//       to use, by comparing the argument types you have used to call the function or operator with the parameter
//       types specified in the definitions. This process of selecting the most appropriate overloaded function or
//       operator is called overload resolution.

class Box
{
    public:
        double getVolume (void) { return length * width * height; }

        void setLength (double l) { length = l; }

        void setWidth (double w) { width = w; }

        void setHeight (double h) { height = h; }

        // Function overload
        void printSpecs (int i);
        void printSpecs (double d);
        void printSpecs (string str);

        // Overload + operator to add two Box objects
        Box operator+ (const Box &b);

        // NOTE: It is important to make operator overloading function a friend of the class because
        //       it would be called without creating an object.
        friend ostream& operator << (ostream &output, Box &box);
        friend istream& operator >> (istream  &input, Box &box);

    private:
        double length;
        double width;
        double height;
};

void Box::printSpecs (int i)
{
    cout << "Box " << i << ":" << endl;
    cout << "Length = " << length << endl;
    cout << "Width  = " << width << endl;
    cout << "Height = " << height << endl;
    cout << "Volume = " << getVolume() << endl;
}

void Box::printSpecs (double d)
{
    cout << "Box " << d << ":" << endl;
    cout << "Length = " << length << endl;
    cout << "Width  = " << width << endl;
    cout << "Height = " << height << endl;
    cout << "Volume = " << getVolume() << endl;
}

void Box::printSpecs (string str)
{
    cout << "Box " << str << ":" << endl;
    cout << "Length = " << length << endl;
    cout << "Width  = " << width << endl;
    cout << "Height = " << height << endl;
    cout << "Volume = " << getVolume() << endl;
}

// Overload + operator to add two Box objects
Box Box::operator+ (const Box &b)
{
    Box box;

    box.length = this->length + b.length;
    box.width = this->width + b.width;
    box.height = this->height + b.height;

    return box;
}

ostream& operator << (ostream &output, Box &box)
{
    output << "Length = " << box.length << "\nWidth  = " << box.width << "\nHeight = " << box.height
           << "\nVolume = " << box.getVolume() << endl;

    return output;
}

istream& operator >> (istream  &input, Box &box)
{
    input >> box.length >> box.width >> box.height;
    return input;
}


int main()
{
    // Objects declaration
    Box Box1;
    Box Box2;
    Box Box3;
    Box Box4;

    // Box1
    Box1.setLength(5.0);
    Box1.setWidth(6.0);
    Box1.setHeight(7.0);

    Box1.printSpecs(1);
    cout << endl;

    // Box2
    Box2.setLength(8.0);
    Box2.setWidth(9.0);
    Box2.setHeight(10.0);

    Box2.printSpecs(2.2);
    cout << endl;

    // Box3 definition
    Box3 = Box1 + Box2;

    Box3.printSpecs("Three");
    cout << endl;

    // Box4 definition
    cout << "Please enter your box dimensions (l w h): ";
    cin >> Box4;
    cout << "Box 4:" << endl;
    cout << Box4;


    return 0;
}
