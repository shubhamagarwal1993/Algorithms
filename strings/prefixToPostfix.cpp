// Prefix: An expression is called prefix expression if operator appears before the operands
// Example: *+AB-CD (Infix: (A+B)*(C-D))

// Postfix: An expression is called postfix expression if operator appears after the operands
// Example: AB+CD-* (Infix: (A+B)*(C-D))
// Computers evaluate using Postfix expression

// Input :  Prefix :  *-A/BC-/AKL
// Output : Postfix : ABC/-AK/L-*
// Prefix to Infix :  A-(B/C)*(A/K)-L
// Infix to Postfix : ABC/-AK/L-*

#include <iostream>
#include <stack>

using namespace std;

bool isOperator(char input) {
    char operator_arr[4] = {'+', '-', '/', '*'};
    int operator_arr_size = sizeof(operator_arr)/sizeof(operator_arr[0]);
    for(int i = 0; i < operator_arr_size; i++) {
        if(operator_arr[i] == input) {
            return true;
        }
    }
    return false;
}

// Read the Prefix expression in reverse order (from right to left)
// If the symbol is an operand, then push it onto the Stack
// If the symbol is an operator, then pop two operands from the Stack
// Create a string by concatenating the two operands and the operator after them
// string = operand1 + operand2 + operator
// And push the resultant string back to Stack
// Repeat the above steps until end of Prefix expression
string prefixToPostfix(string prefix, int prefix_size) {
    stack<string> s;

    for(int i = prefix_size - 1; i >= 0; i--) {
        if(isOperator(prefix[i])) {
            
            // pop 2 operands
            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

            // combine expression
            string exp = op1 + op2 + prefix[i];

            s.push(exp);
        } else {
            s.push(string(1, prefix[i]));
        }
    }
    return s.top();
}

int main() {
    string prefix = "*-A/BC-/AKL";
    int prefix_size = prefix.length();
    cout << prefixToPostfix(prefix, prefix_size) << endl;
    return 0;
}
