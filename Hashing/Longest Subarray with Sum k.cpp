int longestSubarrayWithSumK(vector<int> a, long long k) {
  map <long long, int> mp;
  long long sum = 0;
  int maxLen = 0;
  for(int i = 0; i < a.size(); i++) {
    sum += a[i];
    if(sum == k) {
      maxLen = max(maxLen, i+1);
    }
    long long rem = sum-k;
    if(mp.find(rem) != mp.end()) {
      int len = i - mp[rem];
      maxLen = max(maxLen, len);
    }
    if (mp.find(sum) == mp.end()) {
      mp[sum] = i;
    }
  }
  return maxLen;
}

// Input - k = 2
// arr = {1, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 1, 1, 1, 1, 1, 1}
// Output - 8
