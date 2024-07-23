// Leetcode - 257

void solve(TreeNode* root, string output, vector<string>& ans) {
    if (!root) {
        return;
    }

    output += to_string(root->val);

    if (!root->left && !root->right) {
        ans.push_back(output);
    }

    output += "->";

    solve(root->left, output, ans);
    solve(root->right, output, ans);
}

vector<string> binaryTreePaths(TreeNode* root) {
    vector<string> ans;
    string output = "";

    solve(root, output, ans);

    return ans;
}

// Input: root = [1,2,3,null,5]
// Output: ["1->2->5","1->3"]
