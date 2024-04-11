int atmostK(vector<int> &nums, int k) {
  int l = 0, r = 0, cnt = 0;
  map<int, int> mp;
  while (r < nums.size()) {
    ++mp[nums[r]];
    while (mp.size() > k) {
      --mp[nums[l]];
      if (mp[nums[l]] == 0) {
        mp.erase(nums[l]);
      }
      ++l;
    }
    cnt += (r - l + 1);
    ++r;
  }
  return cnt;
}
int kDistinctSubarrays(vector<int> &nums, int n, int k) {
  int ans = atmostK(nums, k) - atmostK(nums, k - 1);
  return ans;
}

// Input: nums = [1,2,1,2,3], k = 2
// Output: 7
// Explanation: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]
