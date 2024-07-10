// Leetcode - 101

bool solve(TreeNode* left, TreeNode* right) {
    if (left == NULL || right == NULL) {
        return left == right;
    }

    if (left->val != right->val) {
        return false;
    }

    return (solve(left->left, right->right)) &&
           (solve(left->right, right->left));
}

bool isSymmetric(TreeNode* root) {
    return (root == NULL) || (solve(root->left, root->right));
}

// Input: root = [1,2,2,3,4,4,3]
// Output: true
