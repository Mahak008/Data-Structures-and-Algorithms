// Reverse the infix expression.
// Change the parentheses.
// Convert the modified expression to postfix.
// Reverse the postfix expression to get the prefix expression.


#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int prec(char c) {
        if (c == '^') {
            return 3;
        } else if (c == '/' || c == '*') {
            return 2;
        } else if (c == '-' || c == '+') {
            return 1;
        } else {
            return -1;
        }
    }
    
    string infixToPrefix(string s) {
        // Step 1: Reverse the infix expression
        reverse(s.begin(), s.end());
        
        // Step 2: Replace '(' with ')' and vice versa
        for (unsigned i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                s[i] = ')';
            } else if (s[i] == ')') {
                s[i] = '(';
            }
        }
        
        stack<char> st;
        string res;
        
        // Step 3: Convert the modified expression to postfix
        for (unsigned i = 0; i < s.length(); i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || isdigit(s[i])) {
                res += s[i];
            } else if (s[i] == '(') {
                st.push(s[i]);
            } else if (s[i] == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                while (!st.empty() && prec(st.top()) > prec(s[i])) {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        // Step 4: Reverse the postfix expression to get the prefix
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    Solution ob;
    cout << ob.infixToPrefix(exp) << endl; // Expected output: -+a*b^-^cde+f*ghi
    return 0;
}

// OUTPUT: -+a*b^-^cde+f*ghi
