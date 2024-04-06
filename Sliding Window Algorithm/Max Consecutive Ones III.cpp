// With atmost k zeroes
int longestSubSeg(vector<int> &nums, int n, int k) {
  int l = 0, r = 0, maxLen = 0, zero = 0;
  while (r < n) {
    if (nums[r] == 0) {
      ++zero;
    }
    if (zero > k) {
      if (nums[l] == 0) {
        --zero;
      }
      ++l;
    }
    maxLen = max(maxLen, (r - l + 1));
    ++r;
  }
return maxLen;
}
