vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        root = st.top();
        st.pop();

        ans.push_back(root->val);

        if (root->left) {
            st.push(root->left);
        }

        if (root->right) {
            st.push(root->right);
        }
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 2, 3, 7, 6, 4, 1
