#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <numeric>      // std::accumulate

using namespace std;

#define INT_SIZE 32

void print2NonRepeatingNumbers(int arr[], int size) {
    int xor_sum = arr[0];          // xor of all elements
    int set_bit_no;                // Will have only single set bit of xor
    int i;
    int x = 0, y = 0;

    // Get the xor of all elements in arr[] and {1, 2 .. n}
    for(i = 1; i < size; i++)
        xor_sum ^= arr[i];

    //cout << xor_sum << endl;

    // Get the rightmost set bit in set_bit_no
    set_bit_no = xor_sum & ~(xor_sum-1);

    //cout << set_bit_no << endl;

    // divide elements in two sets by comparing rightmost set bit of xor with bit at same position in each element
    for(i = 0; i < size; i++) {
        if(arr[i] & set_bit_no)
            x = x ^ arr[i];                // XOR of first set in arr[]
        else
            y = y ^ arr[i];                // XOR of second set in arr[]
    }

    cout << "The two repeating elements are: " << x << " " << y << endl;
    return;
}

/*
 * All numbers are in even pairs
 * Only one number is in odd pair
 *
 * XOR same number twice gives 0
 * XOR on all numbers will make result 0 from even and give the odd occuring no
 */
void print1NonRepeatingNumber(int arr[], int size) {

    int xor_all = 0;

    for(int i = 0; i < size; i++) {
        xor_all ^= arr[i];
    }

    cout << "The non-repeating number is: " << xor_all << endl;
    return;
}

/*
 * All numbers occur 3 times
 * Only one number appears once
 *
 * Go through all elements in array, maintaining 2 values:
 *   - ones: The bits that have appeared 1st, 4th, or 7th time
 *   - twos: The bits that have appeared 2nd, 5th, or 8th time
 * return the values of ones
 *
 * Time complexity: O(N), Space complexity: O(1)
 */
void printOnlyNonRepeatingNumberMethod1(int arr[], int arr_size) {
    int ones = 0;
    int twos = 0;
    int common_bit_mask = 0;

    // For every new element in array, find out the common set bits in the new element and previous value of ‘ones’
    // These common set bits are actually the bits that should be added to ‘twos’
    // So do bitwise OR of the common set bits with ‘twos’
    // ‘twos’ also gets some extra bits that appear third time. These extra bits are removed later
    // Update ‘ones’ by doing XOR of new element with previous value of ‘ones’
    // There may be some bits which appear 3rd time. These extra bits are also removed later
    // Both ‘ones’ and ‘twos’ contain those extra bits which appear 3rd time
    // Remove these extra bits by finding out common set bits in ‘ones’ and ‘twos’
    for(int i = 0; i < arr_size; i++) {

        /*
         * Expression "ones & arr[i]" gives the bits that are there in both 'ones' and new element from arr[]
         * We add these bits to 'twos' using bitwise OR
         *
         * Value of 'twos' will be set as 0, 3, 3 and 1 after 1st, 2nd, 3rd and 4th iterations respectively
         */
        twos = twos | (ones & arr[i]);

        /*
         * XOR the new bits with previous 'ones' to get all bits appearing odd number of times
         * 
         * Value of 'ones' will be set as 3, 0, 2 and 3 after 1st, 2nd, 3rd and 4th iterations respectively
         */
        ones = ones ^ arr[i];
  
        /* The common bits are those bits which appear third time
         * So these bits should not be there in both 'ones' and 'twos'
         *
         * common_bit_mask contains all these bits as 0, so that the bits can be removed from 'ones' and 'twos'
         *
         * Value of 'common_bit_mask' will be set as 00, 00, 01 and 10 after 1st, 2nd, 3rd and 4th iterations respectively
         */
        common_bit_mask = ~(ones & twos);
 
        /* Remove common bits (the bits that appear third time) from 'ones'
         *
         * Value of 'ones' will be set as 3, 0, 0 and 2 after 1st, 2nd, 3rd and 4th iterations respectively
         */
        ones &= common_bit_mask;
 
        /* Remove common bits (the bits that appear third time) from 'twos'
         *
         * Value of 'twos' will be set as 0, 3, 1 and 0 after 1st, 2nd, 3rd and 4th itearations respectively
         */
        twos &= common_bit_mask;
 
        // uncomment this code to see intermediate values
//        cout << ones << " " << twos << " " << common_bit_mask << endl;
    }

    cout << "The non-repeating number is: " << ones << endl;
    return;
}

/*
 * All numbers occur 3 times
 * Only one number appears once
 *
 * Sum the bits in same positions for all the numbers and take modulo with 3
 * The bits for which sum is not multiple of 3, are the bits of number with single occurrence
 *
 * Time complexity: O(N), Space complexity: O(1)
 */
void printOnlyNonRepeatingNumberMethod2(int arr[], int arr_size) {

    int result = 0;

    for(int i = 0; i < INT_SIZE; i++) {
        int sum = 0;
        
        int x = (1 << i);
        for(int j = 0; j < arr_size; j++) {
            // if bit is set at i for all ints in array
            if(arr[j] & x) {
                sum++;
            }
        }

        // if bit is not 0, our number has this bit set
        if(sum % 3) {
            result |= x;
        }
    }

    cout << "The non-repeating number is: " << result << endl;
    return;
}

/*
 * All numbers occur 3 times
 * Only one number appears once
 *
 * Time complexity: O(N), Space complexity: O(1)
 */
void printOnlyNonRepeatingNumberMethod3(int arr[], int arr_size) {

    // Use: ( 3*(sum_of_array_without_duplicates) – (sum_of_array) ) / 2

    // Array [] : [a, a, a, b, b, b, c, c, c, d]
    // ( 3*(a+b+c+d) – (a + a + a + b + b + b + c + c + c + d) ) / 2

    // put all numbers in set
    set<int> set_arr;
    for(int i = 0; i < arr_size; i++) {
        set_arr.insert(arr[i]);
    }
    int set_sum = std::accumulate(set_arr.begin(), set_arr.end(), 0);

    int arr_sum = 0;
    for(int i = 0; i < arr_size; i++) {
        arr_sum += arr[i];
    }

    int result = ((3*set_sum) - arr_sum) / 2;

    cout << "The non-repeating number is: " << result << endl;
    return;
}

int main() {
    // one non-repeating number
    int arr[] = {2, 2, 3, 3, 4, 4, 5};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    print1NonRepeatingNumber(arr, arr_size);

    // all but one element appear more than once
    int arr2[] = {12, 1, 12, 3, 12, 1, 1, 2, 3, 3};
    int arr2_size = sizeof(arr2)/sizeof(arr2[0]);
    printOnlyNonRepeatingNumberMethod1(arr2, arr2_size);
    printOnlyNonRepeatingNumberMethod2(arr2, arr2_size);
    printOnlyNonRepeatingNumberMethod3(arr2, arr2_size);

    int arr3[] = {4, 2, 4, 5, 2, 3, 1, 5};
    int arr3_size = sizeof(arr3)/sizeof(arr3[0]);
    print2NonRepeatingNumbers(arr3, arr3_size);

    return 0;
}

