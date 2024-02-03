long long maxArea(long long A[], int len) {
  long long max = INT_MIN;
  int l = 0, r = len-1;
  if(len == 1) {
    return 0;
  }
  while(l < r) {
    int area = min(A[l], A[r]) * (r-l);
    if(area > max) {
      max = area;
    }
    if(A[l] < A[r]) {
      l++;
    }
    else {
      r--;
    }
  }
  return max;
}

// Input : 1,5,4,3
// Output: 6
