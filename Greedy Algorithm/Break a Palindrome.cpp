// Leetcode - 1328
string breakPalindrome(string p) {
    int n = p.length();
    if (n == 1) {
        return "";
    }

    for (int i = 0; i < n / 2; i++) {
        if (p[i] != 'a') {
            p[i] = 'a';
            return p;
        }
    }

    p[n - 1] = 'b';
    return p;
}

// Input: palindrome = "abccba"
// Output: "aaccba"
// Explanation: There are many ways to make "abccba" not a palindrome, such as "zbccba", "aaccba", and "abacba".
// Of all the ways, "aaccba" is the lexicographically smallest.
