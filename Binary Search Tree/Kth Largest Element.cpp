void morrisTraversal(Node* root, int k, int &ans) {
  if (!root)
    return;

  Node* curr = root;
  int cnt = 0;

  while (curr) {
    if (!curr->left) {
      ++cnt;

      if (cnt == k) {
        ans = curr->data;
      }

      curr = curr->right;
    } else {
      Node* prev = curr->left;

      while (prev->right && prev->right != curr) {
        prev = prev->right;
      }

      if (prev->right == NULL) {
        prev->right = curr;
        curr = curr->left;
      } else {
        prev->right = NULL;
        ++cnt;

        if (cnt == k) {
          ans = curr->data;
        }

        curr = curr->right;
      }
    }
  }
}

int countNodes(Node* root) { 
  if (root == NULL) {
    return 0;
  }

  if (root->left == NULL && root->right == NULL) {
    return 1;
  }

  int left = countNodes(root->left);
  int right = countNodes(root->right);

  return 1 + left + right;
}

int kthLargest(Node *root, int k) {
  int n = countNodes(root);
  int ans = 0;
  morrisTraversal(root, n - k + 1, ans);
  return ans;
}

// Input:
//       4
//     /   \
//    2     9
// k = 2 

// Output: 4
