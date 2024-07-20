// Leetcode - 1382

class Solution {
public:
    void solve(TreeNode* root, vector<int>& in) {
        TreeNode* curr = root;

        while (curr) {
            if (!curr->left) {
                in.push_back(curr->val);
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
                    in.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }

    TreeNode* inorderToBST(int start, int end, vector<int>& inorder) {
        if (start > end)
            return NULL;

        int mid = (start + end) / 2;

        TreeNode* root = new TreeNode(inorder[mid]);
        root->left = inorderToBST(start, mid - 1, inorder);
        root->right = inorderToBST(mid + 1, end, inorder);

        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        solve(root, in);
        return inorderToBST(0, in.size() - 1, in);
    }
};

// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
