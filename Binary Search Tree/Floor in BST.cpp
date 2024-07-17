int floor(Node* root, int x) {
    if (root == NULL) 
        return -1;

    Node*curr = root;
    int fl = -1;
    
    while(curr) {
        if(x == curr->data) {
            fl = curr->data;
            return fl;
        }
        else if(x < curr->data) {
            curr = curr->left;
        }
        else {
            fl = curr->data;
            curr = curr->right;
        }
    }
    
    return fl;
}

// Input:
// n = 7               2
//                      \
//                       81
//                     /     \
//                  42       87
//                    \       \
//                     66      90
//                    /
//                  45
// x = 87
// Output:
// 87
