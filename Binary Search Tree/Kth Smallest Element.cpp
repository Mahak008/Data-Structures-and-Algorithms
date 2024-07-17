// Leetcode - 230

void morrisTraversal(TreeNode* root, int& k, int& ans) {
    if (!root)
        return;

    TreeNode* curr = root;
    int cnt = 0;

    while (curr) {
        if (!curr->left) {
            ++cnt;

            if (cnt == k) {
                ans = curr->val;
            }

            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            while (prev->right && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = NULL;
                ++cnt;

                if (cnt == k) {
                    ans = curr->val;
                }

                curr = curr->right;
            }
        }
    }
}

int kthSmallest(TreeNode* root, int k) {
    int ans = 0;
    morrisTraversal(root, k, ans);
    return ans;
}

// Input: root = [3,1,4,null,2], k = 1
// Output: 1
