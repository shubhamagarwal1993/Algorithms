#include <iostream>

using namespace std;

void printNextGreaterNumber(int digits[], int digits_size) {
    if(digits_size <= 1) {
        cout << "not possible";
        return;
    }

    int first_smaller_digit_index = 0;
    for(int i = digits_size - 2; i >= 0; i--) {
        if(digits[i+1] > digits[i]) {
            first_smaller_digit_index = i;
            break;
        }
    }
    if(first_smaller_digit_index == 0) {
        cout << "not possible";
        return;
    }

    int greater_digit = digits[first_smaller_digit_index + 1];
    int greater_digit_index = first_smaller_digit_index + 1;
    for(int i = first_smaller_digit_index + 1; i < digits_size; i++) {
        if((digits[i] > digits[first_smaller_digit_index]) && (digits[i] < greater_digit)) {
            greater_digit = digits[i];
            greater_digit_index = i;
        }
    }

    // swap the smaller and next greater digit
    swap(digits[first_smaller_digit_index], digits[greater_digit_index]);

    // sort the rest of the digits to get the smallest number
    sort(digits+first_smaller_digit_index+1, digits+greater_digit_index+1);

    // print the number
    cout << "next larger number: ";
    for(int i = 0; i < digits_size; i++) {
        cout << digits[i];
    }
    cout << endl;
}

// Driver Program to test above function
int main() {
    int digits[] = {5, 3, 4, 9, 7, 6};
    int digits_size = sizeof(digits)/sizeof(digits[0]);
    printNextGreaterNumber(digits, digits_size);
	return 0;
}
