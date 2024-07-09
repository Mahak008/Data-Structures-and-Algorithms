// Leetcode - 103

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> ans;

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);
    int flag = 0;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                q.push(node->left);
            }

            if (node->right) {
                q.push(node->right);
            }

            level.push_back(node->val);
        }

        if (flag == 1) {
            reverse(level.begin(), level.end());
        }

        ans.push_back(level);

        flag = !flag;
    }

    return ans;
}

// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]
