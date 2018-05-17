#include <iostream>
#include <unordered_map>
using namespace std;

int partition (int array[], int l, int r) {
    int x = array[r];
    int i = (l - 1);

    for (int j = l; j <= r- 1; j++)
    {
        if (array[j] <= x)
        {
            i++;
            swap (array[i], array[j]);
        }
    }

    swap (array[i + 1], array[r]);
    return (i + 1);
}

int kth_smallest_quicksort(int array[], int l, int r, int k) {
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1)
    {
        // Partition the array around last element and get position of pivot element in sorted array
        int pos = partition(array, l, r);

        // If position is same as k
        if (pos-l == k-1)
            return array[pos];

        if (pos-l > k-1)  // If position is more, recur for left subarray
            return kth_smallest_quicksort(array, l, pos-1, k);

        // Else recur for right subarray
        return kth_smallest_quicksort(array, pos+1, r, k-pos+l-1);
    }
 
    // If k is more than number of elements in array
    return -1;
}

void k_most_used_words(string input, int k) {

    // declaring unordered map
    unordered_map<string, int> frequencyMap;

    // insert words and frequency
    string word = "";
    for(int i = 0; i < input.size(); i++) {
        if(input[i] == ' ') {
            // insert into map
            if(frequencyMap[word]) {
                frequencyMap[word] = frequencyMap[word] + 1;
            } else {
                frequencyMap[word] = 1;
            }
            word = "";
        } else if(i == input.size() - 1) {
            if(frequencyMap[word]) {
                frequencyMap[word] = frequencyMap[word]++;
            } else {
                frequencyMap[word] = 1;
            }
            word = "";
        } else {
            word = word + input[i];
        }
    }

    std::unordered_map<std::string, int>::iterator it = frequencyMap.begin();
    while(it != frequencyMap.end()) {
        cout << it->first << " " << it->second << endl;
        it++;
    }

    return;
}

void getKMostUsedWords(string input, int k) {

    // Min heap of size k - these are the k most frequent words
    MinHeap* minHeap = createMinHeap(k);
    // calculate frequency of all the words in a hashmap with key word and value frequency

    // using frequency as key for minHeap, add pair object of word and its frequency
        // if minHeap is full
            // if element's frequency is greater than mininum (top) element, then remove top and insert element
            // else do nothing
    // once all words are scanned, minHeap now contains the top k most frequent words
}

int main() {

    // top k most used words
    int k = 5;

    string input = "a b b c c c d d d d e e e e e f f f f f f h h h h h h h i i i i i i i i j j j j j j j j j";

    //finding the k most used words
    k_most_used_words(input, k);

    // Assumption: enough main memory to accomodate all words
    // The data structure should be dynamic so new words can be added
    // Time: O(nlogk), Space: O(n)
    getKMostUsedWords(input, k);

    return 0;
}
