// When duplicates are present

bool searchInARotatedSortedArrayII(vector<int> &arr, int k) {
  int low = 0, high = arr.size() - 1;
  while (low <= high) {
    int mid = (low + high) / 2;

    if (arr[mid] == k) {
      return true;
    }

    if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
      ++low;
      --high;
      continue;
    }

    if (arr[low] <= arr[mid]) {
      if (arr[low] <= k && k <= arr[mid]) {
        high = mid - 1;
      } else {
        low = mid + 1;
      }
    } else {
      if (arr[mid] <= k && k <= arr[high]) {
        low = mid + 1;
      } else {
        high = mid - 1;
      }
    }
  }
  return 0;
}

// Input: 2
// 3, 1, 2, 3, 3, 3, 3, 3
// Output: 2
