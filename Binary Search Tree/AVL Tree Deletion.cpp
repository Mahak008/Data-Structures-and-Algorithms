class Node {
    int data, height;
    Node *left, *right;
    Node(int x) {
        data = x;
	height = 1;
	left = right = NULL;
    }
};

int getHeight(Node* root) {
    if(!root) {
        return 0;
    }
    
    return root->height;
}

int getBalance(Node* root) {
    return getHeight(root->left) - getHeight(root->right);
}

Node* rightRotation(Node* root) {
    Node* child = root->left;
    Node* childRight = child->right;
    
    child->right = root;
    root->left = childRight;
    
    // Update Height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
    return child;
}

Node* leftRotation(Node* root) {
    Node* child = root->right;
    Node* childLeft = child->left;
    
    child->left = root;
    root->right = childLeft;
    
    // Update Height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));
    
    return child;
}



// Tree = 
//         4
//       /   \
//      2     6
//     / \   / \  
//    1   3 5   7

// N = 4
// Values to be deleted = {4,1,3,6}

// Input: Value to be deleted = 4
// Output:
//         5    
//       /   \
//      2     6
//     / \     \  
//    1   3     7

// Input: Value to be deleted = 1
// Output:
//         5    
//       /   \
//      2     6
//       \     \  
//        3     7

// Input: Value to be deleted = 3
// Output:
//         5    
//       /   \
//      2     6
//             \  
//              7

// Input: Value to be deleted = 6
// Output:
//         5    
//       /   \
//      2     7

