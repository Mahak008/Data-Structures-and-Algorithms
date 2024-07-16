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

// Using Stack
void flatten(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        if (curr->right) {
            st.push(curr->right);
        }

        if (curr->left) {
            st.push(curr->left);
        }

        if (!st.empty()) {
            curr->right = st.top();
        }

        curr->left = NULL;
    }
}

// Morris Traversal Approach

void flatten(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != NULL) {
        if (curr->left) {
            TreeNode* prev = curr->left;

            while (prev->right) {
                prev = prev->right;
            }

            prev->right = curr->right; // rightmost element of left subtree is connected to right of curr
            curr->right = curr->left; // now root ka right will point to root ka left
            curr->left = NULL; // root ka left will be null
        }
        curr = curr->right;
    }
}

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
