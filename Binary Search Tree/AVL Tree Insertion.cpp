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
