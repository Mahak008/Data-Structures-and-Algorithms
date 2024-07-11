// Recursive Depth-First Traversal (Preorder Traversal) Approach
// Conversion Logic (convertTree Function):
// It calculates the diff = left_data + right_data - root->data; 
// if diif > 0, update root
// If diff < 0, it recursively adjusts the subtree using the increment function.

// Increment Function (increment):
// Adjusts a given node and its descendants by a specified diff value.
// It recursively adjusts the left or right child (if present) by adding diff to their data.

void increment(Node* node, int diff)  { 
  if (node->left != nullptr) { 
    node->left->data = node->left->data + diff; 
    increment(node->left, diff); 
  } 
    
  else if (node->right != nullptr) { 
    node->right->data = node->right->data + diff; 
    increment(node->right, diff); 
  } 
} 

void convertTree(Node* root) {
  int left_data = 0, right_data = 0, diff; 
  if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
    return; 
  }

  else { 
    convertTree(root->left); 
    convertTree(root->right); 
    
    if (root->left != nullptr) 
      left_data = root->left->data; 
    
    if (root->right != nullptr) 
        right_data = root->right->data; 
      
    diff = left_data + right_data - root->data; 
    
    if (diff > 0) {
      root->data = root->data + diff; 
    
    if (diff < 0) 
      increment(root, -diff);
  }
}


// Input:
//           50
//        /      \
//       7        2
//     /   \    /   \
//    3     5  1    30

// Output:
//           50
//        /      \
//       19       31
//     /   \    /    \
//    14    5  1     30
