void rotateMatrix(vector<vector<int>> &mat) {
  // Write your code here.
  for (int i = 0; i < mat.size() - 1; i++) {
    for (int j = i + 1; j < mat.size(); j++) {
      swap(mat[i][j], mat[j][i]);
    }
  }
  for (int i = 0; i < mat.size(); i++) {
    reverse(mat[i].begin(), mat[i].end());
  }
}

// Input : 
// 1,2,3
// 4,5,6
// 7,8,9

// Output : 
// 7,4,1
// 8,5,2
// 9,6,3
