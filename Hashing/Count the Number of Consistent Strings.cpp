// Leetcode - 1684

int countConsistentStrings(string allowed, vector<string>& words) {
    unordered_set<char> st;

    for (const char& ch : allowed) {
        st.insert(ch);
    }

    int cnt = 0;

    for (const string& s : words) {
        bool b = true;

        for (const char& c : s) {
            if (st.find(c) == st.end()) {
                b = false;
            }
        }

        if (b) {
            cnt++;
        }
    }

    return cnt;
}

// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
