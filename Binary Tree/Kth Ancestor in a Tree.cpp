void markParents(Node* root, unordered_map<Node*, Node*> &mp) {
    queue <Node*> q;
    q.push(root);
    
    while(!q.empty()) {
        Node* cur = q.front();
        q.pop();
        
        if(cur->left) {
            q.push(cur->left);
            mp[cur->left] = cur;
        }
        
        
        if(cur->right){
            q.push(cur->right);
            mp[cur->right] = cur;
        }
    }
}

Node* findNode(Node* root, int node) {
    if(!root) {
        return NULL;
    }
    
    if(root->data == node) {
        return root;
    }
    
    Node* leftNode = findNode(root->left, node);
    
    if(leftNode) {
        return leftNode;
    }
    
    Node* rightNode = findNode(root->right, node);
    
    if(rightNode) {
        return rightNode;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    unordered_map<Node*, Node*> mp;
    markParents(root, mp);
    
    Node* curr = findNode(root, node);
    
    if(!root || !curr) {
        return -1;
    }
    
    while(k > 0 && curr != NULL) {
        curr = mp[curr];
        k -= 1;
    }
    
    if (!curr) {
        return -1;  // k is greater than the number of ancestors
    }
    
    
    return curr->data;
}

// Input:
// k = 1 
// node = 3

//       1
//     /   \
//     2     3

// Output:
// 1
