int leftHeight(TreeNode* root, int& diameter) {
    if (root == NULL) {
        return 0;
    }

    int lH = leftHeight(root->left, diameter);
    int rH = leftHeight(root->right, diameter);

    diameter = max(diameter, (lH + rH));
    return 1 + max(lH, rH);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    leftHeight(root, diameter);

    return diameter;
}
