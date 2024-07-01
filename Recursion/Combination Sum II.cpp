void solve(vector<int>& candidates, int target, int index, vector<int> output, vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(output);
        return;
    }

    for (int i = index; i < candidates.size(); ++i) {
        if (i > index && candidates[i] == candidates[i - 1]) {
            continue;
        }

        if (candidates[i] > target) {
            break;
        }

        // Include the element
        output.push_back(candidates[i]);
        solve(candidates, target - candidates[i], i + 1, output, ans);
        output.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(candidates, target, index, output, ans);

    return ans;
}
