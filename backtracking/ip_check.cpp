#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

#define MIN_IP_STRING_LEN 7
#define MAX_IP_STRING_LEN 15
#define MAX_IP_VALUE 255
#define MIN_IP_VALUE 0
#define ASCII_NUM_0 48
#define ASCII_NUM_9 57
#define IP_SEGMENTS_COUNT 4

bool checkValidIpSegment(string ip_addr_segment) {

    if(ip_addr_segment.length() == 0) {
        return false;
    }

    // each segment should lie from 0 to 255
    if((stoi(ip_addr_segment) < MIN_IP_VALUE) || (stoi(ip_addr_segment) > MAX_IP_VALUE)) {
        // cout << "Given IP segment " << ip_addr_segment << " out of range" << endl;
        return false;
    }
    return true;
}

bool checkValidIp(string ip_addr) {

    // ip addr string length check
    if((ip_addr.length() > MAX_IP_STRING_LEN)
    && (ip_addr.length() < MIN_IP_STRING_LEN)) {
        cout << "Given ip length invalid" << endl;
        return false;
    }

    // count for 3 dots in string
    size_t ip_addr_break_points = count(ip_addr.begin(), ip_addr.end(), '.');
    if(ip_addr_break_points != 3) {
        cout << "Given ip segments count invalid" << endl;
        return false;
    }

    // split ip addr segments into vector
    stringstream ip_addr_ss(ip_addr);
    string ip_addr_segment;
    vector<string> ip_addr_vec;
    while(getline(ip_addr_ss, ip_addr_segment, '.')) {
        ip_addr_vec.push_back(ip_addr_segment);
    }
    if(ip_addr_vec.size() != 4) {
        cout << "Given ip segments count invalid" << endl;
        return false;
    }

    // loop over each segment
    for(int i = 0; i < ip_addr_vec.size(); i++) {
        ip_addr_segment = ip_addr_vec[i];
        if(!checkValidIpSegment(ip_addr_segment)) {
            return false;
        }
    }

    return true;
}

bool printAllValidIpAddr(string ip_string, int ip_string_length, vector<string> vec) {

    // base case - vec size is 4 and ip_string_length is 0
    if((ip_string_length == 0) && (vec.size() == IP_SEGMENTS_COUNT)){
        for(int i = 0; i < vec.size(); i++) {
            cout << vec[i];
            if(i < vec.size() - 1) {
                cout << ".";
            }
        }
        cout << endl;
        return true;
    }

    for(int i = 0; i <= ip_string_length; i++) {
        string ip_addr_segment = ip_string.substr(0, i);
        if(ip_addr_segment.length() == 0) {
            continue;
        }

        if(checkValidIpSegment(ip_addr_segment)) {
            vec.push_back(ip_addr_segment);
            bool foundIp = printAllValidIpAddr(ip_string.substr(i), ip_string_length - i, vec);
            if(foundIp) {
                vec.clear();
                // if only the first ip address found is needed, uncomment below line
                //return true;
            } else {
                vec.pop_back();
            }
        }
    }

    return false;
}

bool stringOfDigits(string str, int ip_string_length) {

    for(int i = 0; i < ip_string_length; i++) {
        char curr_char = str[i];
        int char_ascii = int(curr_char);
        if((char_ascii < ASCII_NUM_0) || (char_ascii > ASCII_NUM_9)) {
            return false;
        }
    }
    return true;
}

int main() {

    string ip_addr = "1.1.-1.1";
    if(checkValidIp(ip_addr)) {
        cout << ip_addr << " is a valid ip address" << endl << endl;
    } else {
        cout << ip_addr << " is not a valid ip address" << endl << endl;
    }

    string ip_string = "256545";
    int ip_string_length = ip_string.length();
    vector<string> vec;
    // check if given string contains only digits
    if(stringOfDigits(ip_string, ip_string_length)) {
        cout << "All possible ip addresses for " << ip_string << endl;
        printAllValidIpAddr(ip_string, ip_string_length, vec);
        cout << endl;
    } else {
        cout << "Given ip address " << ip_string << " contains non-digits" << endl << endl;
    }

    return 0;
}

