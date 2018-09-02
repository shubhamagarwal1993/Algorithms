#include <iostream>

using namespace std;

bool sellIceCream(int bills[], int bills_size) {

    int change[2] = {0, 0};

    for(int curr_bill_index = 0; curr_bill_index < bills_size; curr_bill_index++) {
        int curr_bill = bills[curr_bill_index];

        if(curr_bill == 5) {
            change[0]++;
        } else if(curr_bill == 10) {
            if(change[0] < 1) {
                return false;
            }

            change[0]--;
            change[1]++;
        } else if(curr_bill == 20) {
            if(change[1] > 0) {
                change[1]--;
                if(change[0] > 0) {
                    change[0]--;
                } else {
                    return false;
                }
            } else {
                if(change[0] > 3) {
                    change[0] -= 3;
                } else {
                    return false;
                }
            }
        }
    }

    return true;
}

int main() {

    // A queue of people are waiting to buy ice cream from you
    // Each person buys one ice cream, which sells for $5
    // Each customer is holding a bill of $5, $10 or $20
    // Initial balance is 0
    // Find whether you will be able to make change for every customer in the queue. You must serve customers in the order they come in
    // For example
    // 5, 5, 5, 10, 20 -> true
    // 5, 5, 10 -> true
    // 10, 10 -> false

    //int bills[] = {5, 5, 5, 10, 20};
    int bills[] = {5, 5, 10};
    //int bills[] = {10, 10};
    int bills_size = sizeof(bills)/sizeof(bills[0]);
    if(sellIceCream(bills, bills_size)) {
        cout << "Change possible" << endl;
    } else {
        cout << "Change not possible" << endl;
    }

    return 0;
}
