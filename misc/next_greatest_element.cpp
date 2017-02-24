#include <iostream>

int josephus(int n, int k) {
	cout << "n: " << n << "k: " << k << endl;
	if (n == 1)
		return 1;
	else
		/* The position returned by josephus(n - 1, k) is adjusted because the
		recursive call josephus(n - 1, k) considers the original position 
		k%n + 1 as position 1 */
		return (josephus(n - 1, k) + k-1) % n + 1;
}

// Driver Program to test above function
int main() {
	int n = 5;
	int k = 2;
	printf("The chosen place is %d", josephus(n, k));
	return 0;
}
