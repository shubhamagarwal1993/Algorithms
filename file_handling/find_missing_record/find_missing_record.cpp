#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

int main() {

	// open file
    string line;
    ifstream input_file ("test.csv");

    if(input_file.is_open()) {
    	// header - throw it away
    	getline(input_file, line);

        while(getline(input_file, line)) {
            stringstream test(line);
            string segment;
            vector<string> seglist;

            while(getline(test, segment, ',')) {
                seglist.push_back(segment);
            }

            for(int i = 0; i < seglist.size(); i++) {
            	cout << seglist[i] << "-";
            }
            cout << endl;
        }
    }

    input_file.close();

	// close file
	return 0;
}
