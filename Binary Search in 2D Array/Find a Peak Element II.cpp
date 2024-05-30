int findMaxIndex(vector<vector<int>>&v, int n, int m, int col) {
  int maxValue = -1, index = -1;
  for(int i = 0; i < n; i++) {
    if(v[i][col] > maxValue) {
      maxValue = v[i][col];
      index = i;
    }
  }
  return index;
}

vector<int> findPeakGrid(vector<vector<int>>& mat) {
  int n = mat.size();
  int m = mat[0].size();
  int low = 0, high = m-1;
  
  while(low <= high) {
    int mid = (low + high)/2;
    int maxEle = findMaxIndex(mat, n, m, mid);
    int left = (mid-1 >= 0) ? mat[maxEle][mid-1] : -1;
    int right = (mid+1 < m) ? mat[maxEle][mid+1] : -1;

    if(mat[maxEle][mid] > left && mat[maxEle][mid] > right) {
      return {maxEle, mid};
    }
    else if(mat[maxEle][mid] < left) {
      high = mid - 1;
    }
    else {
      low = mid + 1;
    }
  }
  return {-1, -1};
}

