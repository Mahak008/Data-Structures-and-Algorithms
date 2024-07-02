// Time Limit Exceeded

void solve(vector<char> s, int index, vector<string>& ans) {
    if (index >= s.size()) {
        ans.push_back(string(s.begin(), s.end()));
        return;
    }

    for (int i = index; i < s.size(); i++) {
        swap(s[i], s[index]);
        solve(s, index + 1, ans);
        swap(s[i], s[index]);
    }
}
string getPermutation(int n, int k) {
    vector<char> s;
    for (int i = 1; i <= n; i++) {
        s.push_back('0' + i);
    }
    vector<string> ans;
    int index = 0;
    solve(s, index, ans);

    sort(ans.begin(), ans.end());
    return ans[k - 1];
}

// Optimized Approach


// Input: n = 3, k = 3
// Output: "213"
