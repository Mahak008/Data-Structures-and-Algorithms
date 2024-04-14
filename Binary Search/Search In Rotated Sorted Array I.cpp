int search(vector<int> &arr, int n, int k) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == k) {
      return mid;
    } else if (arr[low] <= arr[mid]) {
      if (arr[low] <= k && k <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else if (arr[mid] <= arr[high]) {
      if (arr[mid] < arr[high]) {
        if (arr[mid] <= k && k <= arr[high]) {
          low = mid + 1;
        } else {
          high = mid - 1;
        }
      }
    }
  }
  return -1;
}

// Input: 3
// 8 9 4 5
// Output: -1 
