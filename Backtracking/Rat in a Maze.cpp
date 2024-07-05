void solve(int row, int col, vector<vector<int>> &m, int n, vector<vector<int>> visited, string move, vector<string>&ans) {
  if(row == n-1 && col == n - 1) {
    ans.push_back(move);
    return;
  }    
        
  //left
  if(col-1 >= 0 && !visited[row][col-1] && m[row][col-1] == 1) {
    visited[row][col] = 1;
    solve(row, col-1, m, n, visited, move + 'L', ans);
    visited[row][col] = 0;
  }
        
  //up
  if(row-1 >= 0 && !visited[row-1][col] && m[row-1][col] == 1) {
    visited[row][col] = 1;
    solve(row-1, col, m, n, visited, move + 'U', ans);
    visited[row][col] = 0;
  }
        
  //right
  if(col+1 < n && !visited[row][col+1] && m[row][col+1] == 1) {
    visited[row][col] = 1;
    solve(row, col+1, m, n, visited, move + 'R', ans);
    visited[row][col] = 0;
  }
        
  //down
  if(row+1 < n && !visited[row+1][col] && m[row+1][col] == 1) {
    visited[row][col] = 1;
    solve(row+1, col, m, n, visited, move + 'D', ans);
    visited[row][col] = 0;
  }
}
    
vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string>ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  string move = "";
  int row = 0, col = 0;
        
  if(m[0][0] == 1) {
    solve(row, col, m, n, visited, move, ans);
  }
        
  return ans;
}


// Alternate Method


struct Direction {
    pair<int, int> move;
    char symbol;
};

void solve(int row, int col, vector<vector<int>> &m, int n, 
  vector<vector<int>> visited, string next, vector<string>&ans, 
  vector<Direction>& dir) {
    
  if(row == n-1 && col == n - 1) {
    ans.push_back(next);
    return;
  }    
        
  visited[row][col] = 1;
        
  for (auto& d : dir) {
    int i = row + d.move.first;
    int j = col + d.move.second;

    if (i >= 0 && i < n && j >= 0 && j < n && m[i][j] == 1 && !visited[i][j]) {
      solve(i, j, m, n, visited, move + d.symbol, ans, dir);
    }
  }
        
  visited[row][col] = 0;
}
    
vector<string> findPath(vector<vector<int>> &m, int n) {
  vector<string>ans;
  vector<vector<int>> visited(n, vector<int>(n, 0));
  int row = 0, col = 0;
  string next = "";
        
  vector<Direction> dir = {
    {{1, 0}, 'D'}, // Down
    {{0, -1}, 'L'}, // Left
    {{0, 1}, 'R'}, // Right
    {{-1, 0}, 'U'} // Up
  };
        
  if(m[0][0] == 1) {
    solve(row, col, m, n, visited, next, ans, dir);
  }
        
  return ans;
}

// Input: N = 4
// m[][] = {{1, 0, 0, 0},
//          {1, 1, 0, 1}, 
//          {1, 1, 0, 0},
//          {0, 1, 1, 1}}
// Output: DDRDRR DRDDRR
