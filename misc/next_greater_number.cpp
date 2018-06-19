#include <iostream>

using namespace std;

void printNextGreaterNumber(int digits[], int digits_size) {
    if(digits_size <= 1) {
        cout << "  not possible";
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
        cout << "  not possible" << endl;
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
}

void printNumber(int digits[], int digits_size) {
    for(int i = 0; i < digits_size; i++) {
        cout << digits[i];
    }
}

// Driver Program to test above function
int main() {

    int digits1[] = {5, 3, 4, 9, 7, 6};
    int digits_size1 = sizeof(digits1)/sizeof(digits1[0]);
    cout << "original number: ";
    printNumber(digits1, digits_size1);
    printNextGreaterNumber(digits1, digits_size1);
    cout << "  next larger number: ";
    printNumber(digits1, digits_size1);
    cout << endl;

    int digits2[] = {1, 2, 3, 4, 5, 6, 7};
    int digits_size2 = sizeof(digits2)/sizeof(digits2[0]);
    cout << "original number: ";
    printNumber(digits2, digits_size2);
    printNextGreaterNumber(digits2, digits_size2);
    cout << "  next larger number: ";
    printNumber(digits2, digits_size2);
    cout << endl;

    int digits3[] = {5, 4, 3, 2, 1};
    int digits_size3 = sizeof(digits3)/sizeof(digits3[0]);
    cout << "original number: ";
    printNumber(digits3, digits_size3);
    printNextGreaterNumber(digits3, digits_size3);
    cout << endl;

	return 0;
}
