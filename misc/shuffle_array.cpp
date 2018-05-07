#include <iostream>

using namespace std;

void shuffleArray(int input[], int input_size) {

    srand (time(NULL));
    for(int i = input_size - 1; i >= 0; i--) {
        int random_index = rand() % (i+1);
        int temp = input[i];
        input[i] = input[random_index];
        input[random_index] = temp;
    }
}

int main() {
    int input[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int input_size = sizeof(input)/sizeof(input[0]);

    // O(n) time complexity
    shuffleArray(input, input_size);

    for(int i = 0; i < input_size; i++) {
        cout << input[i] << " ";
    }
    cout << endl;

    return 0;
}
