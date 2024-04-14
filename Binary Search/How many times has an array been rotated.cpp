int findKRotation(vector<int> &arr) {
  int n = arr.size();
  int low = 0, high = n - 1, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    if ((arr[low] > arr[mid]) && (arr[high] > arr[mid])) {
      ++low;
      --high;
      continue;
    }
    if (low == high) {
      return low;
    }
    if (arr[high] <= arr[mid]) {
      low = mid + 1;
    } else if (arr[low] <= arr[mid]) {
      high = mid - 1;
    }
  }
  return low;
}

