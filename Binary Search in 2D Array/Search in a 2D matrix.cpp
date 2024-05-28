bool searchMatrix(vector<vector<int>>& matrix, int target) {
  if(matrix.empty()) {
    return false;
  }
  
  int n = matrix.size();
  int m = matrix[0].size();
  int low = 0, high = n * m - 1;

  while(low <= high) {
    int mid = (low + high)/2;
    int row = mid / m;
    int col = mid % m;
    
    if(target == matrix[row][col]) {
      return true;
    }
    else if(target < matrix[row][col]) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return false;
}
