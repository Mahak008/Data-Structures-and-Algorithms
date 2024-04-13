int search(vector<int> &nums, int target) {
  int index = -1, low = 0, high = nums.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (target == nums[mid]) {
      index = mid;
      break;
    } else if (target < nums[mid]) {
      high = mid - 1;
    } else if (target > nums[mid]) {
      low = mid + 1;
    }
  }
  return index;
}
