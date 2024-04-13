int count(vector<int> &nums, int n, int target) {
    int low = 0, high = n - 1, first = -1;
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
	if (first == -1 || last == -1) {
        return 0; // Target not found, return 0
    }
    return last-first+1;
}
