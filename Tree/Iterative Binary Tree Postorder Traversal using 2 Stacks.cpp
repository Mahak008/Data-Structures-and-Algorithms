vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st1, st2;
    st1.push(root);

    while (!st1.empty()) {
        root = st1.top();
        st1.pop();
        st2.push(root);

        if (root->left) {
            st1.push(root->left);
        }

        if (root->right) {
            st1.push(root->right);
        }
    }

    while (!st2.empty()) {
        ans.push_back(st2.top()->val);
        st2.pop();
    }

    return ans;
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 2, 3, 7, 6, 4, 1
