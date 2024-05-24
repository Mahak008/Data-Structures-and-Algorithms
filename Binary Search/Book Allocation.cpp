int sum(vector<int> &nums) {
  int agg = 0;
  for (int i = 0; i < nums.size(); i++) {
    agg += nums[i];
  }
  return agg;
}

int maxEle(vector<int> nums) {
  sort(nums.begin(), nums.end());
  return nums[nums.size() - 1];
}

int subarr(vector<int> &nums, int sum) {
  int start = 0;
  int a = 1;
  for (int i = 0; i < nums.size(); i++) {
    if (start + nums[i] <= sum) {
      start += nums[i];
    } else {
      a += 1;
      start = nums[i];
    }
  }
  return a;
}

int splitArray(vector<int> &nums, int k) {
  int low = maxEle(nums);
  int high = sum(nums);
  while (low <= high) {
    int mid = (low + high) / 2;
    int x = subarr(nums, mid);
    if (x > k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return low;
}


// Input: nums = [7,2,5,10,8], k = 2
// Output: 18
// Explanation: There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
