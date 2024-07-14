// Leetcode - 144

// Iterative Approach

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

// Recursive Approach

void preOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  ans.push_back(root->data);
  preOrder(root->left, ans);
  preOrder(root->right, ans);
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
  preOrder(root, ans);
  return ans;
}

// Morris Traversal

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> preorder;
    TreeNode* cur = root;

    while (cur != NULL) {
        if (!cur->left) {
            preorder.push_back(cur->val);
            cur = cur->right;
        } else {
            TreeNode* prev = cur->left;
            while (prev->right && prev->right != cur) {
                prev = prev->right;
            }
            if (prev->right == NULL) {
                prev->right = cur;
                preorder.push_back(cur->val);
                cur = cur->left;
            } else {
                prev->right = NULL;
                cur = cur->right;
            }
        }
    }
    return preorder;
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 1, 3, 5, 2, 4, 7, 6
