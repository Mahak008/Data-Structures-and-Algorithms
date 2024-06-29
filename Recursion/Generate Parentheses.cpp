void solve(int open, int close, string output, vector<string>& ans) {
    if(open == 0 && close == 0) {
        ans.push_back(output);
        return;
    }

    if(open != 0) {
        string op1 = output;
        op1 += "(";
        solve(open - 1, close, op1, ans);
    }

    if(close > open) {
        string op2 = output;
        op2 += ")";
        solve(open, close-1, op2, ans);
    }
}
vector<string> generateParenthesis(int n) {
    vector<string>ans;
    int open = n, close = n;
    string output= "";

    solve(open, close, output, ans);

    return ans;
}

// Input: n = 3
// Output: "((()))", "(()())", "(())()", "()(())", "()()()"
