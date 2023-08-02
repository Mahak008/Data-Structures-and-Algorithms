int maximumSum( int n,int m, vector<vector<int>> &a) {
  int sum = 0, last = INT_MAX;
    
  for(int i = n-1; i >= 0; i--) {
    int max = INT_MIN;
        
    for(int j = 0; j < m; j++) {
      if(max < a[i][j] && a[i][j] < last) {
        max = a[i][j];
      }
    }
        
    if(max <= 0) {
      return 0;
    }
    else{
      sum += max;
      last = max;
    }
  }
  return sum;
}

// Input : arr[ ] = {{1,7,4,3}, {4,2,5,1}, {9,5,1,8}}
// Output : 18
// Explanation:
// We can select 4 from the first array,
// 5 from second array and 9 from the third array.
