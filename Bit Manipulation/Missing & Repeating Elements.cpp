vector<int> findMissingRepeatingNumbers(vector<int> a) {
  long long s = a.size();
  int xr = 0;
  for(int i = 0; i < s; i++) {
    xr = xr ^ a[i] ^ (i+1);
  }
  
  int bit = (xr & ~(xr - 1));

  int m = 0, n = 0;
  for(int i = 0; i < s; i++) {
    if((a[i] & bit) != 0) {
      m ^= a[i];
    }
    else {
      n ^= a[i];
    }
  }

  for(int i = 1; i <= s; i++) {
    if((i & bit) != 0) {
      m ^= i;
    }
    else {
      n ^= i;
    }
  }

  int cnt = 0;
  for (int i = 0; i < s; i++) {
    if (a[i] == n){
      cnt++;
    }
  }

  vector <int> ans;
  ans.push_back(m);
  ans.push_back(n);

  if (cnt == 2) {
    reverse(ans.begin(), ans.end());
    return ans;
  }
  
  return ans;
}

