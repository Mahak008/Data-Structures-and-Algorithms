// Leetcode - 114

void flatten(TreeNode* root) {
    if (!root)
        return;

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* curr = st.top();
        st.pop();

        if (curr->right)
            st.push(curr->right);
        if (curr->left)
            st.push(curr->left);

        if (!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}

// Time Complexity - O(N)
// Space Complexity - O(N)

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
