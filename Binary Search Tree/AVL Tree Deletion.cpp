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

Node* deleteNode(Node* root, int data) {
    if(!root) {
        return NULL;
    }
    
    if(data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        // Leaf Node
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        
        // Only One Child exists
        else if(root->left && !root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        
        else if(!root->left && root->right) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        
        // Both Child Exists
        else {
            Node* curr = root->right;
            
            while(curr->left) {
                curr = curr->left;
            }
            
            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }
    
    // Update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // Check the balance
    int balance = getBalance(root);
    
    // Left Rotation
    if(balance > 1) {
        if(getBalance(root->left) >= 0) {
            return rightRotation(root);
        }
        // Left Right Rotation
        else if(getBalance(root->left) < 0) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    
    // Right Rotation
    if(balance < -1) {
        if(getBalance(root->right) <= 0) {
            return leftRotation(root);
        }
        // Right Left Rotation
        else if(getBalance(root->right) > 0) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    
    return root;
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

