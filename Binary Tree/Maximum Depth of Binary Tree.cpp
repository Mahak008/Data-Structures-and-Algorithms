// Leetcode - 104

int maxDepth(TreeNode* root) {
  if(root == NULL) {
    return 0;
  }
  
  int lh = maxDepth(root->left);
  int rh = maxDepth(root->right);
  return 1 + max(lh, rh);
}

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
