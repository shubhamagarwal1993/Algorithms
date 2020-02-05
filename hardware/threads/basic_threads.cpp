// C++11 introduced threads, before that we had to use POSIX threads from C
//
// To start a thread we simply need to create a new thread object and pass the executing code to be called
// (i.e, a callable object) into the constructor of the object
// Once the object is created a new thread is launched which will execute the code specified in callable
//
// A callable can be either of the three:
//  - A function pointer
//  - A function object
//  - A lambda expression
//
#include <iostream>
#include <thread>

using namespace std;

void foo(int z) {
    cout << "inside thread called by using function pointer" << endl;
}

class thread_obj {
    public:
        void operator() (int x) {
            cout << "inside thread called by using function object" << endl;
        }
};

int main() {

    // Launch this thread by using function pointer as callable
    thread th1(foo, 3);

    // Launch this thread by using function object as callable
    thread th2(thread_obj(), 3);

    // Launch this thread by using lamda expression as callable
    auto f = [](int x) {
        cout << "inside thread called by lamda function" << endl;
    };
    thread th3(f, 3);

    // wait for the threads to finish
    th1.join();
    th2.join();
    th3.join();

    return 0;
}
