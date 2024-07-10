vector <int> bottomView(Node *root) {
    map<int, int> nodes; // vertical line, node
    queue<pair<Node*, int>> q; // node, level
    vector<int> ans;
    
    if(root == NULL) {
        return ans;
    }

    q.push({root, 0});
    
    while(!q.empty()) {
        auto temp = q.front();
        q.pop();
        
        Node* node = temp.first;
        int x = temp.second;
        
        
        nodes[x] = node->data;
        
        if(node->left) {
            q.push({node->left, x-1});
        }
        
        if(node->right) {
            q.push({node->right, x+1});
        }
    }
    
    for(auto it: nodes) {
        ans.push_back(it.second);
    }
    
    return ans;
}

