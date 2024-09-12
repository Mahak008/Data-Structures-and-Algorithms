// Leetcode - 1684

int countConsistentStrings(string allowed, vector<string>& words) {
    int allMask = 0;

    for (const char& c : allowed) {
        allMask |= (1 << (c - 'a'));
    }

    int cnt = 0;

    for (const string& s : words) {
        int word = 0;

        for (const char& c : s) {
            word |= (1 << (c - 'a'));
        }

        if ((word & allMask) == word) {
            cnt++;
        }
    }

    return cnt;
}

// Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
// Output: 2
