void solve(string digits, string output, int index, string* mapp,
           vector<string>& ans) {
    if (index >= digits.length()) {
        ans.push_back(output);
        return;
    }

    int number = digits[index] - '0';
    string value = mapp[number];

    for (int i = 0; i < value.length(); i++) {
        output += value[i];
        solve(digits, output, index + 1, mapp, ans);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> ans;
    if (digits.length() == 0) {
        return ans;
    }
    string output = "";
    int index = 0;

    string mapp[10] = {"",    "",    "abc",  "def", "ghi",
                       "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solve(digits, output, index, mapp, ans);

    return ans;
}

// Input: digits = "23"
// Output: "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"
