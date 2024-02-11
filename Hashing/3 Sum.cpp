vector<vector<int>> triplet(int n, vector<int> &arr) {
  set<vector<int>> st;
  for (int i = 0; i < n - 1; i++) {
    set<int> s;
    for (int j = i + 1; j < n; j++) {
      int third = -(arr[i] + arr[j]);
      if (s.find(third) != s.end()) {
        vector<int> temp = {arr[i], arr[j], third};
        sort(temp.begin(), temp.end());
        st.insert(temp);
      }
      s.insert(arr[j]);
    }
  }
  vector<vector<int>> ans = {st.begin(), st.end()};
  return ans;
}

// Input : -1 -1 2 0 1
// Output :
// -1 -1 2
// -1 0 1
