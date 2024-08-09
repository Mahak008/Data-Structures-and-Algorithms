// Leetcode - 840

bool isMagicGrid(vector<vector<int>>& grid, int r, int c) {
    unordered_set<int> s;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int num = grid[r + i][c + j];

            if (num < 1 || num > 9 || s.count(num)) {
                return false;
            } else {
                s.insert(num);
            }

            int sum = grid[r][c] + grid[r][c + 1] + grid[r][c + 2];

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    // row
                    if (grid[r + i][c] + grid[r + i][c + 1] +
                            grid[r + i][c + 2] !=
                        sum) {
                        return false;
                    }

                    // col
                    if (grid[r][c + i] + grid[r + 1][c + i] +
                            grid[r + 2][c + i] !=
                        sum) {
                        return false;
                    }
                }
            }

            // diagonal
            if (grid[r][c] + grid[r + 1][c + 1] + grid[r + 2][c + 2] != sum) {
                return false;
            }

            // anti - diagonal
            if (grid[r][c + 2] + grid[r + 1][c + 1] + grid[r + 2][c] != sum) {
                return false;
            }
        }
    }

    return true;
}

int numMagicSquaresInside(vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid.size();

    int cnt = 0;

    for (int i = 0; i <= rows - 3; i++) {
        for (int j = 0; j <= cols - 3; j++) {
            if (isMagicGrid(grid, i, j)) {
                cnt++;
            }
        }
    }

    return cnt;
}

// Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
// Output: 1
