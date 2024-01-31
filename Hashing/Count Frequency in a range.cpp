vector<int>ans(n, 0);
for(int i = 1; i <= n; i++) {
  for(int j = 0; j < n; j++) {
    if(nums[j] == i) {
      ans[i-1]++;
    }
  }
}
return ans;

// Input: ‘n’ = 6 ‘x’ = 9 ‘arr’ = [1, 3, 1, 9, 2, 7]    
// Output: [2, 1, 1, 0, 0, 0]
