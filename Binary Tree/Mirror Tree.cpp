void mirror(Node* node) {
    if(node == NULL) {
        return;
    }    
    
    mirror(node->left);
    mirror(node->right);
    
    Node* temp = node->left;
    node->left = node->right;
    node->right = temp;
}

// Input:
//       10
//      /  \
//     20   30
//    /  \
//   40  60
// Output: 30 10 60 20 40
// Explanation: The tree is
//       10               10
//     /    \  (mirror)    /    \
//    20    30    =>   30    20
//   /  \                     /   \
//  40  60                 60   40
// The inroder traversal of mirror is: 30 10 60 20 40.
