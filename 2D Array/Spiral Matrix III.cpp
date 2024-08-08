// Leetcode - 885

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> ans;
    int left = cStart, top = rStart;
    int right = cStart, bottom = rStart;

    // Directions are: right, down, left, up
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir = 0; // Start with the 'right' direction

    int steps = 0;

    while (ans.size() < rows * cols) {
        for (int i = 0; i < steps / 2 + 1; i++) {
            if (top >= 0 && top < rows && left >= 0 && left < cols) {
                ans.push_back({top, left});
            }

            top += directions[dir][0];
            left += directions[dir][1];
        }

        // Change direction
        dir = (dir + 1) % 4;
        ++steps;
    }

    return ans;
}

// Input: rows = 5, cols = 6, rStart = 1, cStart = 4
// Output: [[1,4],[1,5],[2,5],[2,4],[2,3],[1,3],[0,3],[0,4],[0,5],[3,5],[3,4],[3,3],[3,2],[2,2],[1,2],[0,2],[4,5],[4,4],[4,3],[4,2],[4,1],[3,1],[2,1],[1,1],[0,1],[4,0],[3,0],[2,0],[1,0],[0,0]]
 
