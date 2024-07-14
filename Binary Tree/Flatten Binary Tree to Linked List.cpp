// Leetcode - 114

// Recursive Approach

class Solution {
    TreeNode* prev = NULL;
public:
    void flatten(TreeNode* root) {
        if(!root) return;

        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};

// Morris Traversal Approach

void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            TreeNode* prev = curr->left;

            while (prev->right) {
                prev = prev->right;
            }

            prev->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
