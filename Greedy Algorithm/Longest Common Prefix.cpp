// Leetcode - 14

string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    int n = strs.size();

    sort(strs.begin(), strs.end());
    string first = strs[0];
    string last = strs[n - 1];

    int mini = min(first.length(), last.length());

    for (int i = 0; i < mini; i++) {
        if (first[i] != last[i]) {
            return ans;
        }
        ans += first[i];
    }

    return ans;
}

// Input: strs = ["dog", "racecar", "car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
