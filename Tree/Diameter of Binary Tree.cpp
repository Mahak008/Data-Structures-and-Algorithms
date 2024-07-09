int maxHeight(TreeNode* root, int& diameter) {
    if (root == NULL) {
        return 0;
    }

    int lH = maxHeight(root->left, diameter);
    int rH = maxHeight(root->right, diameter);

    diameter = max(diameter, (lH + rH));
    return 1 + max(lH, rH);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;
    maxHeight(root, diameter);

    return diameter;
}

// Input: root = [1,2,3,4,5]
// Output: 3
// Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].
