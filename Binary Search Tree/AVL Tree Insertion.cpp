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
    
Node* insertToAVL(Node* root, int data) {
    if(!root) {
        return new Node(data);
    }
    
    if(data < root->data) {
        root->left = insertToAVL(root->left, data);
    }
    else if(data > root->data) {
        root->right = insertToAVL(root->right, data);
    }
    else {
        return root;
    }
    
    // Update height
    
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    
    // Balance Height
    
    int balance = getBalance(root);
    
    // Left Rotation
    if(balance > 1) {
        if(data < root->left->data) {
            return rightRotation(root);
        }
        // Left Right Rotation
        else if(data > root->left->data) {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }
    
    // Right Rotation
    if(balance < -1) {
        if(data > root->right->data) {
            return leftRotation(root);
        }
        // Right Left Rotation
        else if(data < root->right->data) {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }
    
    return root;
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

// Time - O(log N)

// Input:
// N = 3
// Values to be inserted = {5,1,4} 

// Output:
// 1 4 5

// Explanation:
// Value to be inserted = 5
//     5

// Value to be inserted = 1
//     5
//    /
//   1
 
// Value to be inserted = 4
//   5                        4
//  /    LR rotation        /   \
// 1    ----------->       1     5
//  \
//  4
// Therefore the inorder of the final tree will be 1, 4, 5.
