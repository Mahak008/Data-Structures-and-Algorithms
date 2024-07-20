// Leetcode - 99

class Solution {
private:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root) {
        if (!root)
            return;

        inorder(root->left);

        if (prev != NULL && root->val < prev->val) {
            if (!first) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }

        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN);

        inorder(root);

        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};

// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
