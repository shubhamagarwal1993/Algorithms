#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

int main() {
	// creating an object of list
	list<int> myList;
	std::list<int>::iterator it;

	// total people
	int N = 5;
	// every kth person is out
	int k = 2;

	for(int i = 1; i <= N; i++) {
		// initializing the list with values
		myList.push_back(i);
	}

	int i = 0;
	// counting upto M times and removing the element
	while(myList.size() > 1) {
		for(i = 1; i <= k; i++ ){
			
		}

//		cout << "remove: " << list.get() << endl;
		myList.remove(i);
	}

	//displaying the remaining node
	//cout << "leader is: " << list.get() << endl;
	for(it = myList.begin(); it!=myList.end(); ++it) {
		std::cout << ' ' << *it;
	}

	cout << endl;
	return 0;

}











// int josephus(int n, int k) {
// 	cout << "n: " << n << " k: " << k << endl;
// 	if (n == 1)
// 		return 1;

// 	int temp = k % n + 1;
// 	cout << "temp: " << temp << endl;
// 	/* The position returned by josephus(n - 1, k) is adjusted because the
// 	recursive call josephus(n - 1, k) considers the original position 
// 	k%n + 1 as position 1 */
// 	return (josephus(n - 1, k) + k-1) % n + 1;
// }

// int jos(int n, int k) {
// 	int curr_pos = 1;

// 	unordered_map<int, int> mymap;

// 	while(mymap.size() != n-1){
// 		cout << "map size: " << mymap.size() << endl;
		
// 		// kill the kth person. if person does not exist. then the next in circle
// 		int kill = (curr_pos + k - 1) % n;
// 		while(1) {
// 			if(mymap[kill]) {
// 				kill = (kill + 1) % n;
// 			} else {
// 				break;
// 			}
// 		}
// 		mymap[kill] = 1;

// 		cout << "curr_pos: " << curr_pos << " kill: " << kill << endl;

// 		curr_pos = kill + 1;
// 		while(1) {
// 			if(mymap[curr_pos]) {
// 				curr_pos = (curr_pos + 1) % n;
// 			} else {
// 				break;
// 			}
// 		}
// 	}
// 	return 0;
// }

// // Driver Program to test above function
// int main() {
// 	int n = 5;
// 	int k = 2;
// 	//printf("The chosen place is %d", josephus(n, k));
// 	jos(n, k);
// 	cout << endl;
// 	return 0;
// }


         // 3    [4]

         // [2]	  5

         //   [1]