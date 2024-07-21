Node* buildTree(map<int, vector<int>>& mp, int nodeIndex) {
    Node* node = new Node(nodeIndex);
        
    if (mp.find(nodeIndex) != mp.end()) {
        vector<int> children = mp[nodeIndex];
        
        if (children.size() > 0)
            node->left = buildTree(mp, children[0]);
        
        if (children.size() > 1)
            node->right = buildTree(mp, children[1]);
    }
    
    return node;
}

Node *createTree(vector<int> parent) {
    map<int, vector<int>> mp;
    Node* root = NULL;
    
    for(int i = 0; i < parent.size(); i++) {
        if(parent[i] == -1) {
            root = new Node(i);
        }
        else {
            mp[parent[i]].push_back(i);
        }
    }
    
    if (root != NULL) {
        root = buildTree(mp, root->data);
    }
    
    return root;
}

// Input: parent[] = [2, 0, -1]
// Output: 2 0 1
// Explanation: the tree generated will
// have a structure like
//              2
//             /   
//            0      
//           /   
//          1     
