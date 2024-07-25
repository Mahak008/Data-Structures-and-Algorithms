// Leetcode - 530

void inorder(TreeNode* root, TreeNode*& prev, int& diff) {
    if (!root) {
        return;
    }

    inorder(root->left, prev, diff);

    if (prev) {
        diff = min(diff, abs(root->val - prev->val));
    }
    prev = root;

    inorder(root->right, prev, diff);
}

int getMinimumDifference(TreeNode* root) {
    TreeNode* prev = NULL;
    int diff = INT_MAX;

    inorder(root, prev, diff);

    return diff;
}

// Time - O(N)
// Space - O(N)

// Input: root = [1,0,48,null,null,12,49]
// Output: 1
