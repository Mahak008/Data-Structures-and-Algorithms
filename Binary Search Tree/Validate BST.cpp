// Leetcode - 98

bool ifBST(TreeNode* root, long long l, long long r) {
    if (!root)
        return true;

    if (root->val > l && root->val < r) {
        return ifBST(root->left, l, root->val) &&
               ifBST(root->right, root->val, r);
    }

    return false;
}

bool isValidBST(TreeNode* root) { 
    return ifBST(root, LLONG_MIN, LLONG_MAX); 
}

// Input: root = [5,1,4,null,null,3,6]
// Output: false
