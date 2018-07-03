## Inheritance
 - Mode of inheritance
   - Public: If we derive a sub class from a public base class. Then the public member of the base class will become public in the derived class and protected members of the base class will become protected in derived class
   - Protected: If we derive a sub class from a Protected base class. Then both public member and protected members of the base class will become protected in derived class
   - Private: If we derive a sub class from a Private base class. Then both public member and protected members of the base class will become Private in derived class

### Types of inheritance
 - Single Inheritance
 ```
    #include <iostream>
    using namespace std;
   
    //Base class
    class Parent {
        public:
            int id_p;
    };
   
    // Sub class inheriting from Base Class(Parent)
    class Child : public Parent {
        public:
            int id_c;
    };

    int main() {
        Child obj1;

        // An object of class child has all data members
        // and member functions of class parent
        obj1.id_c = 7;
        obj1.id_p = 91;
        cout << "Child id is " <<  obj1.id_c << endl;
        cout << "Parent id is " <<  obj1.id_p << endl;

        return 0;
    } 
 ```
 - Multilevel Inheritance
 ```
    #include <iostream>
    using namespace std;
     
    // base class
    class Vehicle {
        public:
            Vehicle() {
                cout << "This is a Vehicle" << endl;
            }   
    };

    class FourWheeler: public Vehicle {
        public:
            FourWheeler() {
                cout << "Objects with 4 wheels are vehicles" << endl;
            }   
    };

    // sub class derived from two base classes
    class Car: public FourWheeler{
        public:
            Car() {
                cout << "Car has 4 Wheels" << endl;
            }   
    };
     
    int main() {   
        // creating object of sub class will invoke the constructor of base classes
        Car mycar;

        // This will print:
            // This is a Vehicle
            // Objects with 4 wheels are vehicles
            // Car has 4 Wheels
        return 0;
    }
 ```
