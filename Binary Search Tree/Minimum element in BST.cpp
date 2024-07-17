int minValue(Node* root) {
  Node*curr = root;
        
  while(curr != NULL && curr->left != NULL) {
    curr = curr->left;
  }
        
  return curr->data;
}

// Input:
//              9
//               \
//                10
//                 \
//                  11
// Output: 9
