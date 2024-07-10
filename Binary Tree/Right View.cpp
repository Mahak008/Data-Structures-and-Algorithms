// Leetcode - 199

vector<int> rightSideView(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    queue<TreeNode*> q;
    q.push(root);

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

        int s = level.size() - 1;
        ans.push_back(level[s]);
    }

    return ans;
}

// Input: root = [1,2,3,null,5,null,4]
// Output: [1,3,4]
