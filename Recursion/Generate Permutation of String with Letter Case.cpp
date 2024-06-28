// Permutation with Case Change

void solve(string s, string output, int index, vector<string>& ans) {
    int n = s.length();

    if (index >= n) {
        ans.push_back(output);
        return;
    }

    // Include the current character as it is
    solve(s, output + s[index], index + 1, ans);

    // If the current character is a letter, change its case and include it
    if (isalpha(s[index])) {
        char toggled;
        if (islower(s[index])) {
            toggled = toupper(s[index]);
        } else {
            toggled = tolower(s[index]);
        }
        solve(s, output + toggled, index + 1, ans);
    }
}

vector<string> letterCasePermutation(string s) {
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(s, output, index, ans);
    return ans;
}

// Input: "a1b2"
// Output: "a1b2", "a1B2", "A1b2", "A1B2"
