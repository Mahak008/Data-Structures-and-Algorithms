int floorSqrt(int n) {
  int low = 0, high = n, ans;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (mid * mid <= n) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return high;
}
