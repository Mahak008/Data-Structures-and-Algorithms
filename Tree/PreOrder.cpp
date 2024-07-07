void preOrder(TreeNode *root, vector<int> &ans) {
  if (root == NULL) {
    return;
  }

  pre.push_back(root->data);
  preOrder(root->left, pre);
  preOrder(root->right, pre);
}

vector<int> preorderTraversal(TreeNode* root) {
  vector<int> ans;
  preOrder(root, ans);
  return ans;
}

