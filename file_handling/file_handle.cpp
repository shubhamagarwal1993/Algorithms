#include <iostream>
#include <fstream>

using namespace std;

int main() {

    string line;
    ifstream input_file ("input.txt");

    if(input_file.is_open()) {

        // create a new file
        ofstream output_file;
        output_file.open("output.txt");

        while(getline(input_file, line)) {
            output_file << line << endl;
        }

        input_file.close();
        output_file.close();
    }
    return 0;
}
