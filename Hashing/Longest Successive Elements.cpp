int longestSuccessiveElements(vector<int> &a) {
  int n = a.size();
  if (n == 0) {
    return 0;
  }
  int max = 1;
  unordered_set<int> s;
  for (int i = 0; i < n; i++) {
    s.insert(a[i]);
  }
  for(auto it : s) {
    if(s.find(it-1) == s.end()) {
      int cnt = 1;
      int x = it;
      while(s.find(x+1) != s.end()) {
        x += 1;
        cnt += 1;
      }
      if(max < cnt) {
          max = cnt;
      }
    }
  }
  return max;
}

Input : 5, 8, 3, 2, 1, 4
Output : 5
