pair<int, int> firstAndLastPosition(vector<int> &nums, int n, int target) {
  int low = 0, high = n - 1, first = -1;
  if (n == 0) {
    return {-1, -1};
  }
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      first = mid;
      high = mid - 1;
    } else if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  low = 0;
  high = n - 1;
  int last = -1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (nums[mid] == target) {
      last = mid;
      low = mid + 1;
    } else if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return {first, last};
}
