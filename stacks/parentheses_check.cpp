#include <iostream>
#include <stack>

using namespace std;

bool parentheses(string str, stack <char> s) {

    if(str.length() == 0) {
        return true;
    }

    if(str.length() % 2 != 0) {
        return false;
    }

    for(int i = 0; i < str.length(); i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(') {
            s.push(str[i]);
        } else if(str[i] == '}' || str[i] == ']' || str[i] == ')') {
            if(s.size() == 0) {
                return false;
            } else {
                char temp = s.top();
                s.pop();
                if(str[i] == '}') {
                    if(temp != '{')
                        return false;
                } else if(str[i] == ']') {
                    if(temp != '[')
                        return false;                    
                } else if(str[i] == ')') {
                    if (temp != '(')
                        return false;                    
                }
            }
        }
    }

    if (s.size() == 0)
        return true;
    return false;
}

int main() {
    string str = "{[()]}";
    stack <char> s;
    if(parentheses(str, s)) {
        cout << "parentheses in string is balanced" << endl;
    } else {
        cout << "parentheses in string is not balanced" << endl;
    }

    return 0;
}

