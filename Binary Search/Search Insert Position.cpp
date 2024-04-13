int searchInsert(vector<int> &arr, int m) {
  int n = arr.size(), low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (m == arr[mid]) {
      return mid;
    } else if (m <= arr[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

// Input: 1, 2, 4, 7
// m = 6 
// Output: 3
