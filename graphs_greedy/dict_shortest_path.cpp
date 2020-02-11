// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord

// startWord    = CAT
// endWord      = DOG
// dictionary   = CAT, BAT, COT, COG, COW, RAT, BUT, CUT, DOG, WEB 
// One shortest transformation is CAT –> COT –> COG –> DOG, length 4

// startWord    = HIT
// endWord      = COG
// dictionary   = HOT, DOT, DOG, LOT, LOG
// One shortest transformation is HIT –> HOT –> LOG –> COG, length 5

// Can be solved using BFS or DFS
// BFS:
//   - Pick startWord and find all words in the dict which have one letter difference among them
//   - Pick one word from all the words, and find all the words in the dict which have one letter difference among them

#include <iostream>
#include <queue>

using namespace std;

#define V 10;

// array to store words in dict
const string dict[10] = {"CAT", "BAT", "COT", "COG", "COW", "RAT", "BUT", "CUT", "DOG", "WEB"};
//                         0      1      2      3      4      5      6      7      8       9

bool oneCharDiff(int curr_index, int given_index) {
    string curr_word = dict[curr_index];
    string new_word = dict[given_index];

    int diff_count = 0;
    for(int i = 0; i < 3; i++) {
        if(curr_word[i] != new_word[i]) {
            diff_count++;
            if(diff_count > 1) {
                return false;
            }
        }
    }
    return true;
}

bool BFS(string start_word, string end_word, int pred[], int dist[]) {

    // words already seen
    bool visited[10];
    queue<int> q;

    // Initialize:
    //     Mark all the vertices as not visited
    //     Dist in INT_MAX so we can compare new shorter distances
    //     pred is all none
    for(int i = 0; i < 10; i++) {
        visited[i] = false;
        dist[i] = INT_MAX;
        pred[i] = -1;
    }

    // Mark the start_word as visited and enqueue it
    int start_word_index = -1;
    for(int i = 0; i < 10; i++) {
        if(dict[i] == start_word) {
            start_word_index = i;
            break;
        }
    }

    if(start_word_index < 0) {
        return false;
    }

    visited[start_word_index] = true;
    q.push(start_word_index);
    dist[start_word_index] = 0;

    while(!q.empty()) {

        // Dequeue a vertex from queue and print it
        int curr_index = q.front();
        q.pop();

        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it visited and enqueue it
        for(int i = 0; i < 10; i++) {
            if(!visited[i] && oneCharDiff(curr_index, i)) {
                visited[i] = true;
                dist[i] = dist[curr_index] + 1;
                pred[i] = curr_index;
                q.push(i);

                // check if we found end_word
                if(dict[i] == end_word) {
                    return true;
                }
            }
        }
    }

    return false;
}

void findShortestPath(string start_word, string end_word) {

    // predecessor[i] array stores predecessor of i
    // distance array stores distance of i from s
    int pred[10];
    int dist[10];

    if(!BFS(start_word, end_word, pred, dist)) {
        cout << "No path between source and dest" << endl;
        return;
    }

    int end_word_index = 8;
    int path_length = 1;
    cout << dict[end_word_index] << " ";
    while(pred[end_word_index] != -1) {
        cout << dict[pred[end_word_index]] << " ";
        path_length++;
        end_word_index = pred[end_word_index];
    }
    cout << endl;
    cout << "Path length: " << path_length << endl;
}

int main() {

    // Time: O(V + E), Space: O(V^2)
    string start_word = "CAT";
    string end_word = "DOG";

    findShortestPath(start_word, end_word);
    return 0;
}

