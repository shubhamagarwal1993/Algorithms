// Reference:- https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html

// Encapsulation - binding togerther data and functions that manipulate them under a single unit
// Inheritance - process by which objects of one class acquire the properties of objects of another class
// Polymorphism - having many forms
//          |-> compile time polymorphism : function loading and operator overloading
//          |-> runtime polymorphism : function overriding

// Example of a circle class to show how OOP works in C++
#include <iostream>

using namespace std;

class Shape {

    private: // data memebers (static attributes)
        double sides;
        string color;

    public: // member functions (dynamic attributes)

        // constructor with default values for data members
        Shape(double sides = 0, string color = "") {
            this->sides = sides;
            this->color = color;
        }

        // copy constructor - constructs a new object when another object is passed into a function by value
        // Pass-by-value for object means calling the copy constructor
        Shape(const Shape &shape) {
            this->sides = shape.sides;
            this->color = shape.color;
        }

        double getSides() const {
            return sides;
        }

        string getColor() const {
            return color;
        }

        void setSides(double sides) {
            this->sides = sides;
        }
};

class Square : public Shape {
    public:
        double getArea() const {
            return 5;
        }
};

int main() {

    // Construct Circle instance in difference ways
    Shape shape1 = Shape(4, "blue");

    // Make a new object by using copy constructor
    Shape shape2 = shape1;

    cout << "shape1" << " Sides=" << shape1.getSides() << " Color=" << shape1.getColor() << endl;
    cout << "shape2" << " Sides=" << shape2.getSides() << " Color=" << shape2.getColor() << endl;

   return 0;
}

