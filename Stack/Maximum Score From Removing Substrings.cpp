// Leetcode - 1717

string removeSubstr(string& s, string& str) {
    stack<char> st;

    for (char& ch : s) {
        if (ch == str[1] && !st.empty() && st.top() == str[0]) {
            st.pop();
        } else {
            st.push(ch);
        }
    }

    string temp = "";
    while (!st.empty()) {
        temp.push_back(st.top());
        st.pop();
    }

    reverse(temp.begin(), temp.end());
    return temp;
}

int maximumGain(string s, int x, int y) {
    int n = s.length();
    int score = 0;

    string maxStr = (x > y) ? "ab" : "ba";
    string minStr = (x < y) ? "ab" : "ba";

    // First Pass
    string temp_first = removeSubstr(s, maxStr);

    int l1 = temp_first.length();

    int charRemoved1 = (n - l1);
    score += (charRemoved1 / 2) * max(x, y);

    // Second Pass
    string temp_second = removeSubstr(temp_first, minStr);

    int l2 = temp_second.length();

    int charRemoved2 = l1 - l2;
    score += (charRemoved2 / 2) * min(x, y);

    return score;
}

// Input: s = "cdbcbbaaabab", x = 4, y = 5
// Output: 19

// Explanation:
// - Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
// - Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
// - Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
// - Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
// Total score = 5 + 4 + 5 + 5 = 19.
