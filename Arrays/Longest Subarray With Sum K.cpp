int longestSubarrayWithSumK(vector<int> a, long long k) {
  int len = 0;
  for(int i = 0; i < a.size()-1; i++) {
    int sum = a[i];
    for(int j = i+1; j < a.size();j++) {
      if(sum == k) {
        len = max(len,(j-i));
      }
      sum += a[j];
    }
  }
  return len;
}

// Input :
// 7 3
// 1 2 3 1 1 1 1

// Output : 3
