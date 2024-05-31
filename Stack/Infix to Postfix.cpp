#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return precedence of operators
    int prec(char c) {
        if (c == '^') {
            return 3;
        } else if (c == '/' || c == '*') {
            return 2;
        } else if (c == '+' || c == '-') {
            return 1;
        } else {
            return -1;
        }
    }

    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        stack<char> st;
        string res;

        for (unsigned i = 0; i < s.length(); i++) {
            // If the character is an operand, add it to the result.
            if (isalpha(s[i]) || isdigit(s[i])) {
                res += s[i];
            }
            // If the character is '(', push it to the stack.
            else if (s[i] == '(') {
                st.push(s[i]);
            }
            // If the character is ')', pop and add to result until '(' is found.
            else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
            }
            // If an operator is encountered
            else {
                while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }

        // Pop all the operators from the stack
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        return res;
    }
};

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    Solution ob;
    cout << ob.infixToPostfix(exp) << endl;
    return 0;
}

// OUTPUT: abcd^e-fgh*+^*+i-
