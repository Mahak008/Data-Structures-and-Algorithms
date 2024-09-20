int countBuildings(vector<int> &height) {
  int n = height.size();
        
  if(n == 0) {
    return 0;
  }
        
  int x = height[0];
  int y = 1;
        
  for(int i = 0; i < n; i++) {
    if(height[i] > x) {
      ++y;
      x = height[i];
    }
  }
        
  return y;
}

// Input: height = [7, 4, 8, 2, 9]
// Output: 3
