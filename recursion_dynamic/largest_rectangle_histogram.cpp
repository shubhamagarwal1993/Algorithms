#include <iostream>

using namespace std;

int largestRect(int arr[], int arr_size) {

    int max_area = 0;
    int curr_area = 0;
    int min_height = INT_MAX;
    int max_width = 0;

    for(int i = 0; i < arr_size; i++) {
        if(arr[i] == 0) {
            curr_area = 0;
            max_width = 0;
            min_height = INT_MAX;
            continue;
        }
        
        if(min_height > arr[i]) {
            min_height = arr[i];
        }

        max_width++;
        curr_area = min_height * max_width;

        if(arr[i] > max_area) {
            max_area = arr[i];
            curr_area = min_height * max_width;
        }
        if(curr_area > max_area) {
            max_area = min_height * max_width;
        }

        cout << max_area << endl;
        cout << curr_area << endl;
        cout << min_height << endl;
        cout << max_width << endl;
        cout << "-------" << endl;
    }
    return max_area;
}

int main() {

    // Time complexity O()
    int arr[] = {6, 1, 5, 4, 5, 2, 6};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    cout << largestRect(arr, arr_size) << endl;

    return 0;
}

