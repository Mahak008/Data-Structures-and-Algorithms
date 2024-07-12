// Leetcode - 222

int countNodes(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (root->left == NULL && root->right == NULL) {
        return 1;
    }

    int left = countNodes(root->left);
    int right = countNodes(root->right);

    return 1 + left + right;
}

// Input: root = [1,2,3,4,5,6]
// Output: 6
