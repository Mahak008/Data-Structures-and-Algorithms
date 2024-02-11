vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
  vector<vector<int>> answer(matrix.size(), vector<int>(matrix[0].size(), 0)); // Create answer with same size of matrix
  vector <int> ans;
  for(int i = 0; i < matrix[0].size(); i++) {
    int maxi = matrix[0][i];
    for(int j = 0; j < matrix.size(); j++) {
      if(matrix[j][i] > maxi) {
        maxi = matrix[j][i];
      }
    }
    ans.push_back(maxi);
  }
        
  for(int i = 0; i < matrix.size(); i++) {
    for(int j = 0; j < matrix[0].size(); j++) {
      if(matrix[i][j] == -1) {
        answer[i][j] = ans[j];
      }
      else {
        answer[i][j] = matrix[i][j];
      }
    }
  }       
  return answer;
}

// Input : 
// 1,2,-1
// 4,-1,6
// 7,8,9
  
// Output : 
// 1,2,9
// 4,8,6
// 7,8,9
