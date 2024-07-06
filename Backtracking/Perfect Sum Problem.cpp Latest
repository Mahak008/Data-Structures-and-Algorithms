void solve(int *candidates, int target, int n, int index, vector<int> output, vector<vector<int>>& ans) {
  if (target == 0) {
    ans.push_back(output);
    return;
  }

  for (int i = index; i < n; ++i) {
    // Skip duplicates
    if (i > index && candidates[i] == candidates[i - 1]) {
      continue;
    }

    if (candidates[i] > target) {
      break;
    }

    output.push_back(candidates[i]);
    solve(candidates, target - candidates[i], n, i + 1, output, ans);
    output.pop_back(); // Backtrack
  }
}

vector<vector<int>> combinationSum2(int * candidates, int n, int target) {
  sort(candidates, candidates+n);
  vector<vector<int>> ans;
  vector<int> output;
  int index = 0;
  solve(candidates, target, n, index, output, ans);

  return ans;
}   

int perfectSum(int arr[], int n, int sum) {
  vector<vector<int>> ans = combinationSum2(arr, n, sum);
  return ans.size();
}

// Input: 
// n = 6, arr = [5, 2, 3, 10, 6, 8], sum = 10
// Output: 
// 3
// Explanation: 
// {5, 2, 3}, {2, 8}, {10} are possible subsets.
