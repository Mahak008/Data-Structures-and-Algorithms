int find_max(vector<int> &nums) {
  int maxi = INT_MIN;
  for (int i = 0; i < nums.size(); i++) {
    if (maxi < nums[i]) {
      maxi = nums[i];
    }
  }
  return maxi;
}
bool find_no(vector<int> &nums, int x, int value) {
  int ans = 0;
  for (int i = 0; i < nums.size(); i++) {
    ans += ceil((double)(nums[i]) / (double)(x));
    if (ans > value) {
      return false;
    }
  }
  return true;
}
int smallestDivisor(vector<int> &nums, int threshold) {
  int low = 1, high = find_max(nums);
  while (low <= high) {
    int mid = (low + high) / 2;
    if (find_no(nums, mid, threshold)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

// Input: nums = [1,2,5,9], threshold = 6
// Output: 5
// Explanation: We can get a sum to 17 (1+2+5+9) if the divisor is 1. 
// If the divisor is 4 we can get a sum of 7 (1+1+2+3) and if the divisor is 5 the sum will be 5 (1+1+1+2). 
