Node * inOrderSuccessor(Node *root, Node *x){
    if(!root) return NULL;
    
    Node* succ = NULL;
    
    while(root) {
        if(x->data >= root->data) {
            root = root->right;
        }
        else {
            succ = root;
            root = root->left;
        }
    }
    
    return succ;
}

// Input:
//       2
//     /   \
//    1     3
// x = 2
// Output: 3 
