vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr) {
  vector<vector<int>> ans;
  sort(arr.begin(), arr.end());
  for (int i = 0; i < arr.size(); i++) {
    if (ans.empty() || arr[i][0] > ans.back()[1]) {
      ans.push_back(arr[i]);
    } else {
      ans.back()[1] = max(ans.back()[1], arr[i][1]);
    }
  }
  return ans;
}

// Input : [1,3], [2,6], [8,10], [15,18]
// Output : [1,6], [8,10], [15,18]
// Explanation : Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
