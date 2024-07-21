Node *RemoveHalfNodes(Node *root) {
  if(!root) {
    return NULL;
  }
        
  root->left = RemoveHalfNodes(root->left);
  root->right = RemoveHalfNodes(root->right);
       
  if(!root->left && !root->right) {
    return root;
  }
        
  if(!root->left) {
    Node* newNode = root->right;
    return newNode;
  }
        
  if(!root->right) {
    Node* newNode = root->left;
    return newNode;
  }
        
  return root;
}

// Input: tree = 5
//             /   \
//           7     8
//         / 
//       2
// Output: 2 5 8
