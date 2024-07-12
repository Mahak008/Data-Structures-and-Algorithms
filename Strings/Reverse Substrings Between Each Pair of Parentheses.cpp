// Leetcode - 1190

string reverseParentheses(string s) {
    stack<int> lastSkipLen;
    string res;

    for (char c : s) {
        if (c == '(') {
            lastSkipLen.push(res.length());
        } else if (c == ')') {
            int l = lastSkipLen.top();
            lastSkipLen.pop();
            reverse(res.begin() + l, res.end());
        } else {
            res.push_back(c);
        }
    }

    return res;
}

// Input: s = "(ed(et(oc))el)"
// Output: "leetcode"
