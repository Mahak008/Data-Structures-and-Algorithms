// Leetcode - 1161

int maxLevelSum(TreeNode* root) {
    if (!root)
        return 0;

    queue<TreeNode*> q;
    q.push(root);

    int level = 1;
    int maxLevel = 0;
    int maxSum = INT_MIN;

    while (!q.empty()) {
        int size = q.size();
        int sum = 0;

        for (int i = 0; i < size; i++) {
            TreeNode* curr = q.front();
            q.pop();
            sum += curr->val;

            if (curr->left) {
                q.push(curr->left);
            }

            if (curr->right) {
                q.push(curr->right);
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            maxLevel = level;
        }
        level++;
    }

    return maxLevel;
}

// Input: root = [1,7,0,7,-8,null,null]
// Output: 2

// Explanation: 
// Level 1 sum = 1.
// Level 2 sum = 7 + 0 = 7.
// Level 3 sum = 7 + -8 = -1.
// So we return the level with the maximum sum which is level 2.
