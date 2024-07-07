void inOrder(TreeNode *root, vector<int> &inOr) {
  if (root == NULL) {
    return;
  }

  inOrder(root->left, inOr);
  inOr.push_back(root->data);
  inOrder(root->right, inOr);
}

void preOrder(TreeNode *root, vector<int> &pre) {
  if (root == NULL) {
    return;
  }

  pre.push_back(root->data);
  preOrder(root->left, pre);
  preOrder(root->right, pre);
}

void postOrder(TreeNode *root, vector<int> &post) {
  if (root == NULL) {
    return;
  }

  postOrder(root->left, post);
  postOrder(root->right, post);
  post.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root) {
  vector<vector<int>> ans;
  vector<int> inOr, pre, post;

  inOrder(root, inOr);
  preOrder(root, pre);
  postOrder(root, post);

  ans.push_back(inOr);
  ans.push_back(pre);
  ans.push_back(post);

  return ans;
}

// The Inorder traversal will be [5, 3, 2, 1, 7, 4, 6].
// The Preorder traversal will be [1, 3, 5, 2, 4, 7, 6].
// The Postorder traversal will be [5, 2, 3, 7, 6, 4, 1].
