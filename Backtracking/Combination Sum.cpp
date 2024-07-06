void solve(vector<int>& candidates, int target, int index, vector<int> output,
           vector<vector<int>>& ans) {
    if (target == 0) {
        ans.push_back(output);
        return;
    }

    if (index >= candidates.size() || target < 0) {
        return;
    }

    // Include the element
    output.push_back(candidates[index]);
    solve(candidates, target - candidates[index], index, output, ans);
    output.pop_back(); // Backtrack

    // Exclude the element
    solve(candidates, target, index + 1, output, ans);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(candidates, target, index, output, ans);

    return ans;
}

// Input: candidates = [2,3,6,7], target = 7
// Output: [[2,2,3],[7]]
