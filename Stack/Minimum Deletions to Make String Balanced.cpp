// Leetcode - 1653

int minimumDeletions(string s) {
    int n = s.length();
    int cnt = 0;
    stack<char> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && s[i] == 'a' && st.top() == 'b') {
            st.pop();
            cnt++;
        } else {
            st.push(s[i]);
        }
    }

    return cnt;
}

// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
