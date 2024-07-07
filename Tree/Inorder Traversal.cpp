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

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 3, 2, 1, 7, 4, 6
