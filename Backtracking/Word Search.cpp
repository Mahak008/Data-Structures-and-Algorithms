bool exist(vector<vector<char>>& board, string word) {
    int n = board.size();
    int m = board[0].size();
    int index = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    vector<pair<int, int>> dir = {
        {1, 0}, {0, -1}, {0, 1}, {-1, 0}}; // Four possible directions

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == word[0] &&
                find(board, word, i, j, index, visited, dir)) {
                return true;
            }
        }
    }
    return false;
}

// Input: board = "A" "B" "C" "E"
//                "S" "F" "C" "S"
//                "A" "D" "E" "E"
//        word = "ABCCED"
// Output: true
