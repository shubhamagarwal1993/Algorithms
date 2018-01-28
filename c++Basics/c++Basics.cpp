// Reference:- https://www.ntu.edu.sg/home/ehchua/programming/cpp/cp3_OOP.html

// Example of a circle class to show how OOP works in C++
#include <iostream>

using namespace std;

class Circle {
    // data memebers (static attributes)
    private:
        double radius;
        string color;
    public:
    // member functions (dynamic attributes)

    // constructor with default values for data members
    Circle(double radius = 1.0, string circle = "red") {
        this->radius = radius;
        this->color = circle;
    }

    // copy constructor - constructs a new object when another object is passed into a function by value
    // Pass-by-value for object means calling the copy constructor
    Circle(const Circle &circle) {
        this->radius = circle.radius;
        this->color = circle.color;
    }

    double getRadius() const {
        return radius;
    }

    string getColor() const {
        return color;
    }

    double getArea() const {
        return radius*radius*3.1416;
    }

    void setRadius(double radius) {
        this->radius = radius;
    }
};

int main() {

    // Construct Circle instance in difference ways
    Circle c1;
    Circle c2 = Circle();

    Circle c3(3.4);
    Circle c4 = Circle(3.4);

    Circle c5(1.2, "blue");
    Circle c6 = Circle(1.2, "blue");

    // Make a new object by using copy constructor
    Circle c7 = c6;
    Circle c8(c4);

    cout << "c1" << " Radius=" << c1.getRadius() << " Area=" << c1.getArea() << " Color=" << c1.getColor() << endl;
    cout << "c2" << " Radius=" << c2.getRadius() << " Area=" << c2.getArea() << " Color=" << c2.getColor() << endl;
    cout << "c3" << " Radius=" << c3.getRadius() << " Area=" << c3.getArea() << " Color=" << c3.getColor() << endl;
    cout << "c4" << " Radius=" << c4.getRadius() << " Area=" << c4.getArea() << " Color=" << c4.getColor() << endl;
    cout << "c5" << " Radius=" << c5.getRadius() << " Area=" << c5.getArea() << " Color=" << c5.getColor() << endl;
    cout << "c6" << " Radius=" << c6.getRadius() << " Area=" << c6.getArea() << " Color=" << c6.getColor() << endl;
    cout << "c7" << " Radius=" << c7.getRadius() << " Area=" << c7.getArea() << " Color=" << c7.getColor() << endl;
    cout << "c8" << " Radius=" << c8.getRadius() << " Area=" << c8.getArea() << " Color=" << c8.getColor() << endl;

   return 0;
}

