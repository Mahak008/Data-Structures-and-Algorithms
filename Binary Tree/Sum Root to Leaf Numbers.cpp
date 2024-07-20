// Leetcode - 129

void solve(TreeNode* root, string output, vector<string>& ans) {
    if (!root) {
        return;
    }

    output += to_string(root->val);

    if (!root->left && !root->right) {
        ans.push_back(output);
    } else {
        solve(root->left, output, ans);
        solve(root->right, output, ans);
    }
}

int sumNumbers(TreeNode* root) {
    vector<string> ans;
    string output;
    int sum = 0;

    solve(root, output, ans);

    for (int i = 0; i < ans.size(); i++) {
        sum += stoi(ans[i]);
    }

    return sum;
}

// Input: root = [1,2,3]
// Output: 25
  
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
