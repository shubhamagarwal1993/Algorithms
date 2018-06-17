#include <iostream>

using namespace std;

void print_valid_pages(int page_start, int page_end, int page_exclude_array[], int page_exclude_array_size) {

    if(page_start <= 0 || page_end <= 0 || page_start > page_end) {
        cout << "page range: NA" << endl;
    } else if(page_start == page_end) {
        cout << "page range: " << to_string(page_start) << endl;
    }

    int page_exclude_array_index = 0;
    string ans = "";
    int page_index = page_start;

    while(page_index <= page_end) {

        // if no more page exclude, just print and break - base case
        if(page_exclude_array_index >= page_exclude_array_size) {
            if(page_end == page_start) {
                if(ans.empty()) {
                    ans = ans + to_string(page_start);
                } else {
                    ans = ans + ", " + to_string(page_start);
                }
            } else {
                if(ans.empty()) {
                    ans = ans + to_string(page_start);
                    ans = ans + "-" + to_string(page_end);
                } else {
                    ans = ans + ", " + to_string(page_start) + "-" + to_string(page_end);
                }
            }
            break;
        }

        if(page_index == page_exclude_array[page_exclude_array_index]) {
            if(page_index == page_start + 1) {
                ans = ans + ", " + to_string(page_index-1);
            } else if(page_start != page_end) {
                if(ans.empty()) {
                    ans = ans + to_string(page_start);
                    ans = ans + "-" + to_string(page_index-1);
                } else {
                    ans = ans + ", " + to_string(page_start) + "-" + to_string(page_index-1);
                }
            }
            page_start = page_index + 1;
            page_index++;
            page_exclude_array_index++;
        } else if((page_index == page_end) && (page_index != page_exclude_array[page_exclude_array_index])) {
            if(page_index == page_start + 1) {
                if(ans.empty()) {
                    ans = ans + to_string(page_start) + "-" + to_string(page_index);
                } else {
                    ans = ans + ", " + to_string(page_index-1);
                }
            } else {
                if(ans.empty()) {
                    ans = ans + to_string(page_start) + "-" + to_string(page_index);
                } else {
                    ans = ans + ", ";
                    ans = ans + to_string(page_start);
                    ans = ans + "-" + to_string(page_index);
                }
            }
            page_start = page_index + 1;
            page_index++;
            page_exclude_array_index++;
        } else {
            page_index++;
        }
    }

    cout << "page range: " << ans << endl;
}

int main() {
    int page_start = 1;
    int page_end = 10;
    int page_exclude_array[] = {4, 6, 7};
    int page_exclude_array_size = sizeof(page_exclude_array)/sizeof(page_exclude_array[0]);
    // ans in this case should be "1-3, 5, 7-10"

    print_valid_pages(page_start, page_end, page_exclude_array, page_exclude_array_size);

    return 0;
}
