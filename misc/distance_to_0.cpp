#include <iostream>
#include <unordered_map>

using namespace std;

int dist_to_0(int * arr, int size) {

	int closet_0 = -1;

	//find the first 0 in arr
	for(int i = 0; i < size; i++) {
		if(arr[i] == 0) {
			closet_0 = i;
		}
	}
	if(closet_0 == -1)
		return -1;

	// left run
	// run through array
	for(int i = 0; i < size; i++) {
		// if current element is 0, update position of 0
		if(arr[i] == 0){
			closet_0 = i;
		// if current element is not 0, and is before index of 0
		} else if(i < closet_0){
			arr[i] = closet_0 - i;
		// if current element is not 0, and is after index of 0
		} else {
			arr[i] = i - closet_0;
		}
	}

	closet_0 = -1;
	// right run
	for(int i = size-1; i >= 0; i--) {
		// if current element is 0, update position of 0
		if(arr[i] == 0){
			closet_0 = i;
		// if current element is not 0, and is before index of 0
		} else if((i < closet_0) && (arr[i] > (closet_0 - i)) && (closet_0 != -1)) {
			arr[i] = closet_0 - i;
		// if current element is not 0, and is after index of 0
		} else if((i > closet_0) && (arr[i] > (i - closet_0)) && (closet_0 != -1)) {
			arr[i] = i - closet_0;
		}
	}	

	return 0;

}

// Driver Program to test above function
int main() {
	int arr[7] = {0,1,1,0,1,1,1};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
	int ret_val = dist_to_0(arr, arr_size);
	if(ret_val == -1) {
		cout << "no 0s found in array. cannot update positions in array" << endl;
	} else {
		for(int i = 0; i < arr_size; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	return 0;
}