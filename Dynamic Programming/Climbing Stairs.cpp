// Leetcode - 70

int solve(vector<int>& dp, int n) {
    if (n == 0 || n == 1) {
        return 1;
    }

    if (dp[n] != -1) {
        return dp[n];
    }

    dp[n] = solve(dp, n - 1) + solve(dp, n - 2);
    return dp[n];
}

int climbStairs(int n) {
    vector<int> dp(n + 1, -1);
    int ans = solve(dp, n);

    return ans;
}

// Input: n = 2
// Output: 2
// Explanation: There are two ways to climb to the top.
// 1. 1 step + 1 step
// 2. 2 steps
