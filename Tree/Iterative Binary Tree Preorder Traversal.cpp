vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        if (node->right) {
            st.push(node->right);
        }

        if (node->left) {
            st.push(node->left);
        }
        ans.push_back(node->val);
    }

    return ans;
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 1, 3, 5, 2, 4, 7, 6
