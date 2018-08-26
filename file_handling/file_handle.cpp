#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    string line;
    ifstream input_file("input.txt");

    if(input_file.is_open()) {

        // total lines in file
        int total_lines = count(istreambuf_iterator<char>(input_file), istreambuf_iterator<char>(), '\n');
        cout << "Total lines in file: " << total_lines << endl;

        // create a new file
        ofstream output_file;
        output_file.open("output.txt");

        while(getline(input_file, line)) {
            output_file << line << endl;

            // count for 3 dots in string
            size_t ip_addr_break_points = count(line.begin(), line.end(), '.');
            if(ip_addr_break_points != 3) {
                // Do something
            }

            // split ip addr segments into vector
            stringstream ip_addr_ss(line);
            string ip_addr_segment;
            vector<string> ip_addr_vec;
            while(getline(ip_addr_ss, ip_addr_segment, '.')) {
                ip_addr_vec.push_back(ip_addr_segment);
            }
            if(ip_addr_vec.size() != 4) {
                // Do something
            }

            // loop over each segment
            for(int i = 0; i < ip_addr_vec.size(); i++) {
                ip_addr_segment = ip_addr_vec[i];
                    // Do something
            }
        }

        input_file.close();
        output_file.close();
    }
    return 0;
}
