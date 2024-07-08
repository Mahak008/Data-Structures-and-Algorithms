int maxHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int lH = maxHeight(root->left);
    int rH = maxHeight(root->right);

    return 1 + max(lH, rH);
}

bool isBalanced(TreeNode* root) {
    if (root == NULL) {
        return true;
    }

    int x = maxHeight(root->left);
    int y = maxHeight(root->right);

    if (abs(x - y) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

// Input: root = [3,9,20,null,null,15,7]
// Output: true
