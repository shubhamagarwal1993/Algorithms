#include <iostream>
#include <unordered_map>

using namespace std;

int evaluateExpression(string expression) {

    // look for parenthesis and evaluate them first
    int expression_pos = std::string::npos;
        evaluateExpression(expression.substr(
    if( != std::string::npos) {
        evaluateExpression(expression.substr(
        cout << "found bracket" << endl;
    }
    return 5;
}

int main() {

    // 1171
    string expression = "(32+201)*5+6";

    cout <<  evaluateExpression(expression) << endl;
    return 0;
}

