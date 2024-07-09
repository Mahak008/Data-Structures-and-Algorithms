vector<vector<int>> preInpost(Node* root) {
    stack <pair<Node*, int>> st;
    st.push(make_pair(root, 1));
    vector<int> pre, in, post;

    if (root == NULL) return {pre, in, post};

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->left) {
                st.push(make_pair(it.first->left, 1));
            }
        }

        else if(it.second == 2) {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);

            if(it.first->right) {
                st.push(make_pair(it.first->right, 1));
            }
        }

        else {
            post.push_back(it.first->data);
        }
    }

    return {pre, in, post};
}

// Input - 1 2 3 4 5 6 7 
// Preorder: 1 2 4 5 3 6 7 
// Inorder: 4 2 5 1 6 3 7 
// Postorder: 4 5 2 6 7 3 1 
