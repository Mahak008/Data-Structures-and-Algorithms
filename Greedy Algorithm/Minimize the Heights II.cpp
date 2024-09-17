int getMinDiff(vector<int> &arr, int k) {
  int n = arr.size();
        
  if(n == 1) {
    return 0;
  }
        
  sort(arr.begin(), arr.end());
  int ans = arr[n-1] - arr[0];
        
  for(int i = 1; i < n; i++) {
    if(arr[i] - k < 0) {
      continue;
    }
            
    int maxi = max(arr[i-1] + k, arr[n-1] - k);
    int mini = min(arr[0] + k, arr[i] - k);
            
    ans = min(ans, maxi - mini);
  }
        
  return ans;
}

// Input: k = 3, arr[] = {3, 9, 12, 16, 20}
// Output: 11
// Explanation: The array can be modified as {3+k, 9+k, 12-k, 16-k, 20-k} -> {6, 12, 9, 13, 17}.The difference between the largest and the smallest is 17-6 = 11. 
