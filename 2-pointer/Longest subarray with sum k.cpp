int longestSubarrayWithSumK(vector<int> a, long long k) {
  int i = 0, j = 0;
  int n = a.size();
  long long sum = a[0];
  int len = INT_MIN;
  while(j < n) {
    while((i <= j) && (sum > k)) {
      sum -= a[i];
      i++;
    }
    if(sum == k) {
      len = max(len, (j-i+1));
    }
    j++;
    if (j < n) {
      sum += a[j];
    }      
  }
  return len;
}

// Input : 3
// 1 2 3 1 1 1 1

// Output : 3
