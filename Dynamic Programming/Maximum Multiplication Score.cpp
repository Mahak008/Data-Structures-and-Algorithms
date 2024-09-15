long long maxScore(vector<int>& a, vector<int>& b) {
    int n = b.size();
    // Initialize a 2D DP array to store the maximum scores at each stage
    vector<vector<long long>> dp(5, vector<long long>(n, LLONG_MIN));

    // Loop through the 4 values of array a
    for (int i = 1; i <= 4; ++i) {
        // Keep track of the maximum dp[i-1][k] as we go through the array
        long long max_so_far = LLONG_MIN;

        for (int j = i - 1; j < n; ++j) {
            if (i == 1) {
                // Base case: i = 1, we are choosing only 1 element
                dp[i][j] = max(dp[i][j], (long long)a[i - 1] * b[j]);
            } else {
                // Use max_so_far instead of iterating over all previous k's
                if (j > 0 && dp[i - 1][j - 1] != LLONG_MIN) {
                    max_so_far = max(max_so_far, dp[i - 1][j - 1]);
                }
                if (max_so_far != LLONG_MIN) {
                    dp[i][j] = max(dp[i][j], max_so_far + (long long)a[i - 1] * b[j]);
                }
            }
        }
    }

    // The maximum score will be stored in dp[4][n-1], after choosing 4 indices
    long long result = LLONG_MIN;

    for (int j = 3; j < n; ++j) {
        result = max(result, dp[4][j]);
    }

    return result;
}

// Input: a = [-1,4,5,-2], b = [-5,-1,-3,-2,-4]
// Output: -1
// Explanation: We can choose the indices 0, 1, 3, and 4. The score will be (-1) * (-5) + 4 * (-1) + 5 * (-2) + (-2) * (-4) = -1.
