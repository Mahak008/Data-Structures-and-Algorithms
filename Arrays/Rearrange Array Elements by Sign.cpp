vector<int> rearrangeArray(vector<int>& nums) {
  int pos = 0, neg = 1;
  int n = nums.size();
  vector<int> ans(n, 0);
  for(int i = 0; i < n; i++) {
    if(nums[i] < 0) {
      ans[neg] = nums[i];
      neg += 2;
    }
    else {
      ans[pos] = nums[i];
      pos += 2;
    }
  }
return ans;

// Input: nums = [3,1,-2,-5,2,-4]
// Output: [3,-2,1,-5,2,-4]
