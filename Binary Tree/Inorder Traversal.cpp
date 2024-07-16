// Leetcode -94

// Iterative Approach

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;

    if (root == NULL) {
        return ans;
    }

    stack<TreeNode*> st;
    TreeNode* node = root;

    while (true) {
        if (node != NULL) {
            st.push(node);
            node = node->left;
        } else {
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            ans.push_back(node->val);
            node = node->right;
        }
    }
    return ans;
}

// Recursive Approach

void inOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left, ans);
  ans.push_back(root->data);
  inOrder(root->right, ans);
}

vector<int> inorderTraversal(TreeNode* root) {
  vector<int> ans;
  inOrder(root, ans);
  return ans;
}

// Morris Traversal

vector<int> inorderTraversal(TreeNode* root) {
    vector<int>inorder;
    TreeNode* cur = root;

    while(cur != NULL) {
        if(!cur->left) { // if left = null, push root to vector and move the pointer to right
            inorder.push_back(cur->val);
            cur = cur->right;
        } else { // if left != null
            TreeNode* prev = cur->left; // store curr->left to prev pointer
            
            while(prev->right && prev->right != cur) { // find the rightmost node of left subtree
                prev = prev->right; 
            }
            
            if(prev->right == NULL) {
                prev->right = cur; // connect the rightmost node of left subtree to root
                cur = cur->left; // move to left
            } else {
                prev->right = NULL; // break the thread
                inorder.push_back(cur->val); // push the value of root to vector
                cur = cur->right; // move to right
            }
        }    
    }
    return inorder;    
}

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 3, 2, 1, 7, 4, 6
