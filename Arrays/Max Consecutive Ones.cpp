int findMaxConsecutiveOnes(vector<int>& nums) {
  int cur = 0, max = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(nums[i] == 1) {
      cur++;
      if(cur > max) {
        max = cur;
      }
    }
    else {
      cur = 0;
    }
  }
  return max;
}

// Input: nums = [1,1,0,1,1,1]
// Output: 3
