bool isPalindrome(const string& s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

void solve(string s, int index, vector<string> output,
           vector<vector<string>>& ans) {
    if (index >= s.length()) {
        ans.push_back(output);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        if (isPalindrome(s, index, i)) {
            output.push_back(s.substr(index, i - index + 1));
            solve(s, i + 1, output, ans);
            output.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> ans;
    vector<string> output;
    int index = 0;

    solve(s, index, output, ans);
    return ans;
}

// Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Input: s = "aab"
// Output: ["a","a","b"], ["aa","b"]
