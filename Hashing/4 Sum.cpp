vector<vector<int>> fourSum(vector<int> &nums, int target) {
  vector<vector<int>> ans;
  set<vector<int>> st;
  for (int i = 0; i < nums.size() - 2; i++) {
    for (int j = i + 1; j < nums.size() - 1; j++) {
      set<int> s;
      for (int k = j + 1; k < nums.size(); k++) {
        int fourth = target - (nums[i] + nums[j] + nums[k]);
        if (s.find(fourth) != s.end()) {
          vector<int> v = {nums[i], nums[j], nums[k], fourth};
          sort(v.begin(), v.end());
          st.insert(v);
        }
        s.insert(nums[k]);
      }
    }
  }
  ans = {st.begin(), st.end()};
  return ans;
}

// Input : 2 2 2 2 1 3
// target = 8

// Output : 2
// Explanation :
// (2+2+2+2) = (2+2+1+3) = 4.
