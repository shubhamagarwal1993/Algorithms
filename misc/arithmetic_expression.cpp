#include <iostream>
#include <unordered_map>

using namespace std;

int left_of_operator(string expression, int pos_of_operator) {
    while(isdigit(expression[pos_of_operator])) {
        pos_of_operator--;
    }
    return pos_of_operator+1;
}

int right_of_operator(string expression, int pos_of_operator) {
    while(isdigit(expression[pos_of_operator])) {
        pos_of_operator++;
    }
    return pos_of_operator-1;
}

string evaluateSimpleExpression(string expression) {

    // Check if multiplication exists
    while(expression.find('*') != std::string::npos) {
        std::size_t pos_operator = expression.find('*');
        // calculate numbers before and after + sign
        int pos_left_of_operator = left_of_operator(expression, pos_operator-1);
        int int_left_of_operator = stoi(expression.substr(pos_left_of_operator, pos_operator));
        int pos_right_of_operator = right_of_operator(expression, pos_operator+1);
        int int_right_of_operator = stoi(expression.substr(pos_operator+1, pos_right_of_operator));
        // add the numbers
        int sum = int_left_of_operator * int_right_of_operator;
        // replace the expression with this
        expression.replace(pos_left_of_operator, pos_right_of_operator+1, to_string(sum));

    }

    // Check if addition exists
    while(expression.find('+') != std::string::npos) {
        std::size_t pos_operator = expression.find('+');
        // calculate numbers before and after + sign
        int pos_left_of_operator = left_of_operator(expression, pos_operator-1);
        int int_left_of_operator = stoi(expression.substr(pos_left_of_operator, pos_operator));
        int pos_right_of_operator = right_of_operator(expression, pos_operator+1);
        int int_right_of_operator = stoi(expression.substr(pos_operator+1, pos_right_of_operator));
        // add the numbers
        int sum = int_left_of_operator + int_right_of_operator;
        // replace the expression with this
        expression.replace(pos_left_of_operator, pos_right_of_operator+1, to_string(sum));
    }
    return expression;
}

string evaluateExpression(string expression) {

    // if no operator left, return
    if( (expression.find('*') == std::string::npos)
     && (expression.find('+') == std::string::npos)
     && (expression.find('(') == std::string::npos)
     && (expression.find(')') == std::string::npos)
     ) {
        cout << expression << endl;
        return expression;
    }

    // look for parenthesis and evaluate them first
    int pos_open_bracket = expression.find_last_of('(');
    int pos_close_bracket = expression.find(')');
    if(pos_open_bracket != std::string::npos) {
        int local_expression_length = pos_close_bracket - pos_open_bracket;
        string local_expression_result = evaluateSimpleExpression(expression.substr(pos_open_bracket+1, local_expression_length-1));
        expression.replace(pos_open_bracket, local_expression_length+1, local_expression_result);

        // check for other brackets
        evaluateExpression(expression);
    }

    return expression;
}

int main() {

    // 1171
    string expression = "((2*(201+32+1)+3)*5+6)";

    evaluateExpression(expression);
    return 0;
}

