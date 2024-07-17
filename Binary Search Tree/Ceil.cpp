int findCeil(Node* root, int input) {
    if (root == NULL) 
        return -1;

    Node*curr = root;
    int ceil = -1;
    
    while(curr) {
        if(input == curr->data) {
            ceil = curr->data;
            return ceil;
        }
        else if(input > curr->data) {
            curr = curr->right;
        }
        else {
            ceil = curr->data;
            curr = curr->left;
        }
    }
    
    return ceil;
}

// Input:
//      10
//     /  \
//    5    11
//   / \ 
//  4   7
//       \
//        8
// X = 6
// Output: 7
