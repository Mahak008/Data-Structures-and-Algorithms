vector<int> luckyNumbers(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    vector<int> min_row(n, INT_MAX), max_col(m, INT_MIN);

    // Find the minimum value in each row
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] < min_row[i]) {
                min_row[i] = matrix[i][j];
            }
        }
    }

    // Find the maximum value in each column
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] > max_col[j]) {
                max_col[j] = matrix[i][j];
            }
        }
    }

    vector<int> res;

    // Check for lucky numbers
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == min_row[i] && matrix[i][j] == max_col[j]) {
                res.push_back(matrix[i][j]);
            }
        }
    }

    return res;
}
