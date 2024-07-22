// Leetcode - 938

int rangeSumBST(TreeNode* root, int low, int high) {
    int res = 0;
    TreeNode* curr = root;

    while (curr) {
        if (!curr->left) {
            if (curr->val >= low && curr->val <= high) {
                res += curr->val;
            }

            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (!prev->right) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;

                if (curr->val >= low && curr->val <= high) {
                    res += curr->val;
                }

                curr = curr->right;
            }
        }
    }

    return res;
}

// Input: root = [10,5,15,3,7,null,18], low = 7, high = 15
// Output: 32
// Explanation: Nodes 7, 10, and 15 are in the range [7, 15]. 7 + 10 + 15 = 32.
