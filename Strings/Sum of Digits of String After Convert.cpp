//Leetcode - 1945

const int NUM = 31;

int getLucky(string s, int k) {
    string st = "";

    for (const char& i : s) {
        int result = (i & NUM);
        st += to_string(result);
    }

    while (k > 0) {
        int sum = 0;

        for (const char& c : st) {
            sum += (c - '0');
        }

        st = to_string(sum);
        k--;
    }

    int ans = stoi(st);
    return ans;
}

// Input: s = "leetcode", k = 2
// Output: 6
// Explanation: The operations are as follows:
// - Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
// - Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
// - Transform #2: 33 ➝ 3 + 3 ➝ 6
// Thus the resulting integer is 6.
