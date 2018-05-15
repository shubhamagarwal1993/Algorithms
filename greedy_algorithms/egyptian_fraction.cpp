// Given n activites with start and finish times
// Select max number of activities that can be performed by a single person. Person can only work on a single activity at a time

// Example: Consider the following 3 activities sorted by finish time
//      start[]  =  {10, 12, 20};
//      finish[] =  {20, 25, 30};
//
// The maximum set of activities that can be executed is {0, 2} (indexes in start[] and finish[])

#include <iostream>

using namespace std;

// Takes array sorted by finish time and applied simple greedy algo
void printEgyptianFraction(int numerator, int denominator) {

    if((numerator == 0) || (denominator == 0)) {
        return;
    }

    if(denominator % numerator == 0) {
        cout << "1/" << (denominator/numerator) << endl;
        return;
    }

    if(numerator % denominator == 0) {
        cout << (numerator/denominator) << endl;
        return;
    }

    if(numerator > denominator) {
        cout << (numerator/denominator) << " + ";
        printEgyptianFraction(numerator % denominator, denominator);
        return;
    }

    if(denominator > numerator) {
        int ceiling = (denominator/numerator) + 1;
        cout << "1/" << ceiling << " + ";
        // To get numerator and denominator to pass, do (6/14) - (1/ceiling) => ()/(6*ceiling - 1*14)/(14 * ceiling)
        printEgyptianFraction(numerator*ceiling - denominator, denominator * ceiling);
        return;
    }

    return;
}

int main() {

    int numerator = 6;
    int denominator = 14;

    printEgyptianFraction(numerator, denominator);

    return 0;
}

