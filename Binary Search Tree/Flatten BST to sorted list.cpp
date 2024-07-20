Node *flattenBST(Node *root) {
    if(!root) return NULL;
    
    Node* curr = root;
    Node* dummy = new Node(-1);
    Node* newNode = dummy;
    
    while(curr) {
        if(!curr->left) {
            newNode->right = curr;
            curr->left  = NULL;
            newNode = newNode->right;
            curr = curr->right;
        }
        else {
            Node* prev = curr->left;
            
            while(prev->right && prev->right != curr) {
                prev = prev->right;
            }
            
            if(!prev->right) {
                prev->right = curr;
                curr = curr->left;
            }
            else {
                prev->right = NULL;
                newNode->right = curr;
                curr->left = NULL;
                newNode = newNode->right;
                curr = curr->right;
            }
        }
    }
    
    return dummy->right;
}

// Input:
//        5
//         \
//          8
//        /   \
//       7     9  
// Output: 5 7 8 9
// Explanation:
// After flattening, the tree looks like this:
//    5
//     \
//      7
//       \
//        8
//         \
//          9
