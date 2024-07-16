// Leetcode - 145

// Iterative Approach
// Using 2 Stacks

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

// Using 1 Stack

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

// Recursive Approach

void postOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  postOrder(root->left, ans);
  postOrder(root->right, ans);
  ans.push_back(root->data);
}

vector<int> postorderTraversal(TreeNode* root) {
  vector<int> ans;
  solve(root, ans);
  return ans;
}

// Morris Traversal

vector <int> postOrder(Node* root) {
    vector<int>post;
    Node*curr = root;
  
    while(curr != NULL) {
        if(!curr->right) {
            post.push_back(curr->data);
            curr = curr->left;
        }
        else {
            Node* prev = curr->right;
            
            while(prev->left && prev->left != curr) {
                prev = prev->left;
            }
            
            if(prev->left == NULL) {
                post.push_back(curr->data);
                prev->left = curr;
                curr = curr->right;
            }
            else {
                prev->left = NULL;
                curr = curr->left;
            }
        }
    }
    
    reverse(post.begin(), post.end());
    return post;
}


// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 2, 3, 7, 6, 4, 1
