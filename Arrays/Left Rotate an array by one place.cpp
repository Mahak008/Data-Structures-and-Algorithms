vector<int> rotateArray(vector<int>& arr, int n) {
  int x = nums[n-1];
  for(int i = (n-1); i >= 0; i--) {
    nums[i] = nums[i-1];
  }
  nums[0] = x;
  return arr;
}

// Input: 'a' = 5, 'arr' = [1, 2, 3, 4, 5]
// Output: [2, 3, 4, 5, 1]
