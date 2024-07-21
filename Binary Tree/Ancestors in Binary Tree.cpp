void markParents(Node* root, unordered_map<Node*, Node*> &mp) {
    queue<Node*>q;
    q.push(root);
    
    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if(curr->left) {
            q.push(curr->left);
            mp[curr->left] = curr;
        }
        
        if(curr->right) {
            q.push(curr->right);
            mp[curr->right] = curr;
        }
    }
}

Node* findTargetNode(Node* root, int target) {
    if (!root) 
        return NULL;
    
    if (root->data == target) 
        return root;
    
    Node* leftResult = findTargetNode(root->left, target);
    
    if (leftResult) 
        return leftResult;
    
    return findTargetNode(root->right, target);
}

vector<int> Ancestors(struct Node *root, int target) {
    vector<int>ans;
    
    if(target == root->data) {
        return ans;
    }
    
    unordered_map<Node*, Node*>mp;
    markParents(root, mp);
    
    Node* targetNode = findTargetNode(root, target);
    
    if (!targetNode) 
        return ans;
        
    Node* currentNode = targetNode;
    
    while (mp.find(currentNode) != mp.end()) {
        currentNode = mp[currentNode];
        ans.push_back(currentNode->data);
    }
    return ans;
}

// Input:
//          1
//        /   \
//       2     3
//     /  \    /  \
//    4   5  6   8
//   /
//  7
// target = 7
// Output: [4 2 1]
