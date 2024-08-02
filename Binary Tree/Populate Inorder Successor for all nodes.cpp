void solve(Node* root, Node*& prev) {
    if(!root) return;
    
    // Traverse the left subtree
    solve(root->left, prev);
    
    // Set the next of the previous node to the current node
    if(prev) {
        prev->next = root;
    }
    
    // Update prev to the current node
    prev = root;
    
    // Traverse the right subtree
    solve(root->right, prev);
}


void populateNext(Node *root) {
    Node* prev = NULL;
    solve(root, prev);
}

// Input:
//        10
//        /  \
//       8   12
//      /
//     3
// Output: 3->8 8->10 10->12 12->-1
// Explanation: The inorder of the above tree is : 3 8 10 12. So the next pointer of node 3 is pointing to 8 , next pointer of 8 is pointing to 10 and so on.And next pointer of 12 is pointing to -1 as there is no inorder successor of 12.
