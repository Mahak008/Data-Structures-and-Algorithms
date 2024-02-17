vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size();
    int hash[n+1] = {0};
    for(int i = 0; i < n; i++) {
        hash[a[i]]++;
    }
    int r = -1, m = -1;
    for(int i = 1; i <= n; i++){
        if(hash[i] == 2) {
            r = i;
        }
        else if(hash[i] == 0) {
            m = i;
        }
        if(r != -1 && m != -1) {
            break;
        }
    }
    vector <int>ans = {r, m};
    return ans;
}

// Optimal Approach

vector<int> findMissingRepeatingNumbers(vector<int> a) {
  long long n = a.size();
  // S - Sn = x - y
  //  S2 - S2N
  long long SN = (n * (n + 1)) / 2;
  long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
  long long S = 0, S2 = 0;
  for (int i = 0; i < n; i++) {
    S += a[i];
    S2 += (long long)a[i] * (long long)a[i];
  }
  long long val1 = S - SN; // x - y
  long long val2 = S2 - S2N;
  val2 = val2 / val1; // x + y
  long long x = (val1 + val2) / 2;
  long long y = x - val1;
  return {(int)x, (int)y};
}
