int find(vector<vector<int>>& grid, int i, int j, vector<pair<int, int>>& dir) {
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ||
        grid[i][j] == 0) {
        return 0;
    }

    int val = grid[i][j];
    grid[i][j] = 0;
    int maxGold = 0;

    for (auto d : dir) {
        int row = i + d.first;
        int col = j + d.second;
        maxGold = max(maxGold, find(grid, row, col, dir));
    }

    grid[i][j] = val;
    return val + maxGold;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int maxGold = 0;
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, find(grid, i, j, dir));
            }
        }
    }

    return maxGold;
}

// Input: grid = [[0,6,0],[5,8,7],[0,9,0]]
// Output: 24
// Explanation:
// [[0,6,0],
//  [5,8,7],
//  [0,9,0]]
// Path to get the maximum gold, 9 -> 8 -> 7.
