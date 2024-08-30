bool isValid(int row, int col, const vector<int>& board) {
  for (int i = 0; i < row; ++i) {
    int prevCol = board[i] - 1;
    if (prevCol == col || prevCol - col == i - row || prevCol - col == row - i) {
      return false;
    }
  }
  return true;
}

void solve(int row, int n, vector<int>& board, vector<vector<int>>& results) {
  if (row == n) {
    results.push_back(board);
    return;
  }
  
  for (int col = 0; col < n; ++col) {
    if (isValid(row, col, board)) {
      board[row] = col + 1; // +1 to match the 1-based index
      solve(row + 1, n, board, results);
      board[row] = 0; // backtrack
    }
  }
}

vector<vector<int>> nQueen(int n) {
  vector<vector<int>> results;
  vector<int> board(n, 0);
  solve(0, n, board, results);
  return results;
}

// Input: 4
// Output: [[2 4 1 3 ],[3 1 4 2 ]]
