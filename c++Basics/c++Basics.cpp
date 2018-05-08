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
        // class members defined with static keyword
        // No matter how many objects of the class are created, there is only one copy of the static member
        // A static member is shared by all objects of the class. Static data is initialized to 0 when first object is created, if no initialization is present
        // We cannot initialize static data in the class, but can initialize it outside the class using the scope operator ::
        //
        static int objectCount;

        // member functions (dynamic attributes)

        // constructor with default values for data members
        Circle(double radius = 1.0, string circle = "red") {
            this->radius = radius;
            this->color = circle;
            objectCount++;
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

        // static member functions are independent of any particular object of the class, and can be called even if no objects of the class exist
        // A static member function can only access static data members, other static member functions, and any other functions from outside the class
        // A statuc member function does not have access to "this" and can only be accessed by scope resolution operator ::, and can be used to determine whether some objects of the class have been created or not
        static int getObjectCount() {
            return objectCount;
        }
};

// initialize static data
int Circle::objectCount = 0;

int main() {

    // Construct Circle instance in difference ways
    Circle c1;
    Circle c2 = Circle();

    cout << "Objects created = " << Circle::getObjectCount() << endl;
    Circle c3(3.4);
    Circle c4 = Circle(3.4);
    cout << "Objects created = " << Circle::getObjectCount() << endl;

    Circle c5(1.2, "blue");
    Circle c6 = Circle(1.2, "blue");

    // Make a new object by using copy constructor
    Circle c7 = c6;
    Circle c8(c4);

    Circle * c9 = new Circle();

    cout << "c1" << " Radius=" << c1.getRadius() << " Area=" << c1.getArea() << " Color=" << c1.getColor() << endl;
    cout << "c2" << " Radius=" << c2.getRadius() << " Area=" << c2.getArea() << " Color=" << c2.getColor() << endl;
    cout << "c3" << " Radius=" << c3.getRadius() << " Area=" << c3.getArea() << " Color=" << c3.getColor() << endl;
    cout << "c4" << " Radius=" << c4.getRadius() << " Area=" << c4.getArea() << " Color=" << c4.getColor() << endl;
    cout << "c5" << " Radius=" << c5.getRadius() << " Area=" << c5.getArea() << " Color=" << c5.getColor() << endl;
    cout << "c6" << " Radius=" << c6.getRadius() << " Area=" << c6.getArea() << " Color=" << c6.getColor() << endl;
    cout << "c7" << " Radius=" << c7.getRadius() << " Area=" << c7.getArea() << " Color=" << c7.getColor() << endl;
    cout << "c8" << " Radius=" << c8.getRadius() << " Area=" << c8.getArea() << " Color=" << c8.getColor() << endl;

    cout << "c9" << " Radius=" << c9->getRadius() << " Area=" << c9->getArea() << " Color=" << c9->getColor() << endl;

    cout << "Total objects = " << Circle::objectCount << endl;
    delete c9;
    cout << "Total objects = " << Circle::objectCount << endl;

   return 0;
}

