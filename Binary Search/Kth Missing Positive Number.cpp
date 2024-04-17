int missingK(vector<int> arr, int n, int k) {
  for (int i = 0; i < n; i++) {
    if (arr[i] <= k) {
      ++k;
    } else {
      break;
    }
  }
  return k;
}

// Optimized Approach
int missingK(vector<int> arr, int n, int k) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    int missing = arr[mid] - (mid + 1);
    if (missing < k) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return (high + k + 1);
}


// Input: arr = [2,3,4,7,11], k = 5
// Output: 9
// Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.
