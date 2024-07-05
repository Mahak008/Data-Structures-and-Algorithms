int find(vector<vector<int>>& grid, int cnt, int index, int start_x,
         int start_y, vector<pair<int, int>>& dir) {
    int ans = 0;

    if (start_x < 0 || start_x >= grid.size() || start_y < 0 ||
        start_y >= grid[0].size() || grid[start_x][start_y] == -1) {
        return 0;
    }

    if (grid[start_x][start_y] == 2) {
        if (index == cnt) {
            return 1;
        }
        return 0;
    }

    grid[start_x][start_y] = -1;

    for (auto d : dir) {
        int row = start_x + d.first;
        int col = start_y + d.second;
        ans += find(grid, cnt, index + 1, row, col, dir);
    }

    grid[start_x][start_y] = 0;
    return ans;
}

int uniquePathsIII(vector<vector<int>>& grid) {
    int cnt = 1, start_x = 0, start_y = 0, index = 0;
    int n = grid.size(), m = grid[0].size();
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                cnt++;
            }
            if (grid[i][j] == 1) {
                start_x = i;
                start_y = j;
            }
        }
    }

    int ans = find(grid, cnt, index, start_x, start_y, dir);
    return ans;
}

// Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,2,-1]]
// Output: 2
// Explanation: We have the following two paths: 
// 1. (0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)
// 2. (0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)
