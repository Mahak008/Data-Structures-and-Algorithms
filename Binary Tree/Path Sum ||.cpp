// Leetcode - 113

void solve(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> output) {
    if (!root) 
        return;

    output.push_back(root->val);

    if (!root->left && !root->right && targetSum == root->val) {
        ans.push_back(output);
    } else {
        solve(root->left, targetSum - root->val, ans, output);
        solve(root->right, targetSum - root->val, ans, output);
    }
}

vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    vector<vector<int>> ans;
    vector<int> output;

    solve(root, targetSum, ans, output);

    return ans;
}

// Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
// Output: [[5,4,11,2],[5,8,4,5]]
// Explanation: There are two paths whose sum equals targetSum:
// 5 + 4 + 11 + 2 = 22
// 5 + 8 + 4 + 5 = 22
