// Leetcode - 1653

int minimumDeletions(string s) {
    int n = s.length();
    vector<int> left_b(n, 0);
    vector<int> right_a(n, 0);

    int cnt_b = 0;
    for (int i = 0; i < n; i++) {
        left_b[i] = cnt_b;

        if (s[i] == 'b') {
            cnt_b++;
        }
    }

    int cnt_a = 0;
    for (int i = n - 1; i >= 0; i--) {
        right_a[i] = cnt_a;

        if (s[i] == 'a') {
            cnt_a++;
        }
    }

    int cnt = INT_MAX;
    for (int i = 0; i < n; i++) {
        cnt = min(cnt, left_b[i] + right_a[i]);
    }

    return cnt;
}

// Input: s = "aababbab"
// Output: 2
// Explanation: You can either:
// Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
// Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
