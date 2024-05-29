// Each row is sorted in increasing order.
// The first integer of each row is greater than the last integer of the previous row.

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

// Input: 
//  1  3  5  7
// 10 11 16 20
// 23 30 34 60
  
// target = 3
// Output: true
