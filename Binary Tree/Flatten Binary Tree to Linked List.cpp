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

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
