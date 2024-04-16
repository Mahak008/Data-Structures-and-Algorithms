int NthRoot(int n, int m) {
  int low = 1, high = m;
  while(low <= high) {
    int mid = (low + high)/2;
    if(pow(mid,n) == m) {
      return mid;
    }
    else if(pow(mid,n) < m) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return -1;
}

// Input: 4 69
// Output: -1
// Explanation: 4th Root of 69 is not an integer, hence -1.
