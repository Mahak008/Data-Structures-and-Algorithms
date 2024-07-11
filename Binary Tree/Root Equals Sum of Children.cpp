bool checkTree(TreeNode* root) {
    int rootVal = root->val;
    int left = 0, right = 0, diff = 0;
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return false;
    }

    checkTree(root->left);
    checkTree(root->right);

    if (root->left)
        left = root->left->val;
    if (root->right)
        right = root->right->val;

    diff = left + right - rootVal;

    if (diff == 0)
        return true;

    return false;
}

// Input:
//        1
//      /   \
//     4    3
//    /  
//   5    
// Output: 0
