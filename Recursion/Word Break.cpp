unordered_set<string> st;

bool solve(int idx, string& s) {
    if (idx >= s.length()) {
        return true;
    }

    if (st.find(s) != st.end()) {
        return true;
    }

    for (int i = 1; i <= s.length(); i++) {
        string temp = s.substr(idx, i);
        if (st.find(temp) != st.end() && solve((idx + i), s)) {
            return true;
        }
    }

    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    int index = 0;

    for (string& word : wordDict) {
        st.insert(word);
    }

    return solve(index, s);
}

// Give TLE, so use dp
// Input: s = "leetcode", wordDict = ["leet","code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
