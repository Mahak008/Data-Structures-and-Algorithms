// Leetcode - 2236

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

// Alternate Approach

bool checkTree(TreeNode* root) {
    if (root == NULL) {
        return false;
    }

    if (root->left == NULL && root->right == NULL) {
        return true;
    }

    int left = 0, right = 0, diff = 0, rootVal = root->val;

    if (root->left)
        left = root->left->val;
    if (root->right)
        right = root->right->val;

    diff = left + right - rootVal;

    if (diff == 0) {
        if (checkTree(root->left) && checkTree(root->right)) {
            return true;
        }
    }

    return false;
}


// Input:
//        1
//      /   \
//     4    3
//    /  
//   5    
// Output: 0
