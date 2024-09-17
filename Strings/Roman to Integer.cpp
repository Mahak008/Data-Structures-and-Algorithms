// Leetcode - 13

int romanToInt(string s) {
    unordered_map<char, int> roman = {{'I', 1},   {'V', 5},   {'X', 10},
                                      {'L', 50},  {'C', 100}, {'D', 500},
                                      {'M', 1000}};

    int ans = 0;
    for (int i = 0; i < s.length(); i++) {
        if (i < s.length() - 1 && roman[s[i]] < roman[s[i + 1]]) {
            ans -= roman[s[i]];
        } else {
            ans += roman[s[i]];
        }
    }

    return ans;
}

// Input: s = "MCMXCIV"
// Output: 1994
// Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
