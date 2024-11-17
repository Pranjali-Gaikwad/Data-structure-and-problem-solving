#include<iostream>
#include<stack>
#include<string>
using namespace std;

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '/' || c == '*') {
        return 2;
    } else if (c == '^') {
        return 3;
    }
    return 0;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string infixtopostfix(string infix) {
    stack<char> s;
    string postfix = ""; 

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the character is an operand, add it to the postfix string
        if (isalnum(c)) {
            postfix += c;
        } 
        // If the character is '(', push it to the stack
        else if (c == '(') {
            s.push(c);
        } 
        // If the character is ')', pop and add to the postfix string until '(' is found
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '(' from the stack
        } 
        // If the character is an operator
        else if (isOperator(c)) {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all the operators from the stack
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infix;
    cout << "Enter an infix expression: ";
    cin >> infix;

    string postfix = infixtopostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}