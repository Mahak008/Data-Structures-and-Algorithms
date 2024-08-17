int maxSquare(int n, int m, vector<vector<int>> mat) {
    if (n == 0 || m == 0) return 0;

    vector<vector<int>> dp(n, vector<int>(m, 0));
    int maxSize = 0;

    // Fill the first row and first column of dp matrix
    for (int i = 0; i < n; i++) {
        dp[i][0] = mat[i][0];
        maxSize = max(maxSize, dp[i][0]);
    }
    
    for (int j = 0; j < m; j++) {
        dp[0][j] = mat[0][j];
        maxSize = max(maxSize, dp[0][j]);
    }

    // Fill the rest of the dp matrix
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (mat[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                maxSize = max(maxSize, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return maxSize;
}

// Input: n = 2, m = 2
// mat = [[1, 1], 
//        [1, 1]]
// Output: 2
// Explanation: The maximum length of a side of the square sub-matrix is 2. The matrix itself is the maximum sized sub-matrix in this case.

// Input: n = 6, m = 5
// mat = [[0, 1, 1, 0, 1], 
//        [1, 1, 0, 1, 0],
//        [0, 1, 1, 1, 0],
//        [1, 1, 1, 1, 0],
//        [1, 1, 1, 1, 1],
//        [0, 0, 0, 0, 0]]
// Output: 3
