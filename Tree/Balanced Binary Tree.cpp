int maxHeight(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int lH = maxHeight(root->left);

    if (lH == -1) {
        return -1;
    }

    int rH = maxHeight(root->right);

    if (rH == -1) {
        return -1;
    }

    if ((abs(lH - rH) > 1)) {
        return -1;
    }

    return (1 + max(lH, rH));
}

bool isBalanced(TreeNode* root) { 
    return maxHeight(root) != -1; 
}


// Input: root = [3,9,20,null,null,15,7]
// Output: true
