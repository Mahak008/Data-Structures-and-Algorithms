bool find(vector<vector<char>>& board, string word, int i, int j, int index,
          vector<vector<int>>& visited, vector<pair<int, int>>& dir) {
    if (index == word.length()) {
        return true;
    }

    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        visited[i][j] || board[i][j] != word[index]) {
        return false;
    }

    visited[i][j] = 1;

    for (auto d : dir) {
        int row = i + d.first;
        int col = j + d.second;

        if (find(board, word, row, col, index + 1, visited, dir)) {
            return true;
        }
    }

    visited[i][j] = 0;
    return false;
}

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
