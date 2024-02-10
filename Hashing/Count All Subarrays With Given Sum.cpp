int findAllSubarraysWithGivenSum(vector<int> &nums, int k) {
  long long sum = 0;
  map<long long, int> mp;
  mp[0] = 1;
  int cnt = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    int rem = sum - k;
    cnt += mp[rem];
    mp[sum] += 1;
  }
  return cnt;
}

// Input : nums = [1,2,3], k = 3
// Output: 2
