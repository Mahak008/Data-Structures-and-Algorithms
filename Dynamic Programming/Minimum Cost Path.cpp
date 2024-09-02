int minimumCostPath(vector<vector<int>>& grid)  {
    int n = grid.size();
    if (n == 0) return 0;
    
    vector<vector<long long>>dp(n, vector<long long>(n, LLONG_MAX));
    dp[0][0] = grid[0][0];
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0) {
                dp[i][j] = min(dp[i][j], dp[i-1][j] + grid[i][j]);
            }
            if (j > 0) {
                dp[i][j] = min(dp[i][j], dp[i][j-1] + grid[i][j]);
            }
        }
    }
  
    return dp[n-1][n-1];    
}

// Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
// Output: 43
// Explanation: The grid is-
// 9 4 9 9
// 6 7 6 4
// 8 3 3 7
// 7 4 9 10
// The minimum cost is-
// 9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.
