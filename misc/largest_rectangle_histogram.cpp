#include <iostream>
#include <stack>

using namespace std;

// For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle, and find the max of all areas
// To calculate area with ‘x’ as smallest bar, we need to know index of the first smaller (smaller than ‘x’) bar on left (left index) of ‘x’ and index of first smaller bar on right (right index) of ‘x’
// Traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen
// When a bar is popped, we calculate the area with the popped bar as smallest bar
// The current index tells us the ‘right index’
// The index of previous item in stack is the ‘left index’
int largestRect(int arr[], int arr_size) {

    stack<int> s;
    int max_area = 0;

    int right_index = 0;
    while(right_index < arr_size) {
        if(s.empty() || (arr[s.top()] <= arr[right_index])) {
            s.push(right_index);
            right_index++;
        } else {

            int top_stack = s.top();
            s.pop();

            int area_with_top = arr[top_stack] * (s.empty() ? right_index : right_index - s.top() - 1);
            if(area_with_top > max_area) {
                max_area = area_with_top;
            }
        }
    }

    // if stack is not empty, we might have had a completely increasing sequence or increasing sequence towards the end
    while(!s.empty()) {
        int top_stack = s.top();
        s.pop();

        int area_with_top = arr[top_stack] * (s.empty() ? right_index : right_index - s.top() - 1);
        if(area_with_top > max_area) {
            max_area = area_with_top;
        }
    }

    return max_area;
}

int main() {

    // Time complexity O(n), Space: O(n)
    int arr[] = {6, 1, 5, 4, 5, 2, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << largestRect(arr, arr_size) << endl;

    return 0;
}

