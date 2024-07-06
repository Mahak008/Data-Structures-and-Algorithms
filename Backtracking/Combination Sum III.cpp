void solve(vector<int>& v, int n, int k, int index, vector<int> output, vector<vector<int>>& ans) {
    if (n == 0 && output.size() == k) {
        ans.push_back(output);
        return;
    }

    if (output.size() > k) {
        return;
    }

    for (int i = index; i < v.size(); ++i) {
        if (v[i] > n) {
            break;
        }

        // Include the element
        output.push_back(v[i]);
        solve(v, n - v[i], k, i + 1, output, ans);
        output.pop_back(); // Backtrack
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int> v;
    for (int i = 1; i <= 9; i++) {
        v.push_back(i);
    }

    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;

    solve(v, n, k, index, output, ans);

    return ans;
}

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.
