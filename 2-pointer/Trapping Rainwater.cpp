int trap(vector<int>& height) {
  int n = height.size();
  int left[n], right[n];
  
  left[0] = height[0];
  for(int i = 1; i < n; i++) {
    left[i] = max(left[i-1], height[i]);
  }

  right[n-1] = height[n-1];
  for(int i = n-2; i >= 0; i--) {
    right[i] = max(right[i+1], height[i]);
  }

  int sum = 0;
  for(int i = 0; i < n; i++) {
    sum += (min(right[i], left[i]) - height[i]);
  }
  return sum;
}

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// left = [0,1,1,2,2,2,2,3,3,3,3,3]
// right = [3,3,3,3,3,3,3,3,2,2,2,1]
// Output: 6


