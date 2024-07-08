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

// Input
//          1
//        /   \
//      3       4
//    /  \     /  \
//   5    2   7    6

// Output: 5, 2, 3, 7, 6, 4, 1
