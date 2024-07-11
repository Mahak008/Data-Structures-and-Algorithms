// Leetcode - 662

int widthOfBinaryTree(TreeNode* root) {
    if (!root)
        return 0;

    int ans = 0;
    queue<pair<TreeNode*, unsigned long long>> q; // stores node and index
    q.push({root, 0});

    while (!q.empty()) {
        int size = q.size();
        unsigned long long min_idx =
            q.front().second; // to begin indexing with 0
        unsigned long long first, last;

        for (int i = 0; i < size; i++) {
            unsigned long long cur_idx = q.front().second - min_idx;
            TreeNode* node = q.front().first;
            q.pop();

            if (i == 0)
                first = cur_idx;

            if (i == size - 1)
                last = cur_idx;

            if (node->left) {
                q.push({node->left, 2 * cur_idx + 1});
            }

            if (node->right) {
                q.push({node->right, 2 * cur_idx + 2});
            }
        }
        ans = max(ans, (int)(last - first + 1));
    }
    return ans;
}

// Input: root = [1,3,2,5,3,null,9]
// Output: 4
// Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
