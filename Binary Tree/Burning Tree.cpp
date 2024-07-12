void markParents(Node* root, unordered_map<Node*, Node*>& parent_track) {
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        if (curr->left) {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }

        if (curr->right) {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

Node* findNode(Node* root, int target) {
    if (!root) return nullptr;
    if (root->data == target) return root;
    Node* left = findNode(root->left, target);
    if (left) return left;
    return findNode(root->right, target);
}

int minTime(Node* root, int target)  {
    unordered_map<Node*, Node*> parent_track;
    markParents(root, parent_track);
    
    unordered_map<Node*, bool> visited;
    queue<Node*>q;
    int ans = 0;
    
    Node* targetNode = findNode(root, target);
    if (!targetNode) return -1;  // target node not found
    
    q.push(targetNode);
    visited[targetNode] = true;
    
    while(!q.empty()) {
        int size = q.size();
        bool flag = false;
        
        for(int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            
            if (curr->left && !visited[curr->left]) {
                q.push(curr->left);
                visited[curr->left] = true;
                flag = true;
            }

            if (curr->right && !visited[curr->right]) {
                q.push(curr->right);
                visited[curr->right] = true;
                flag = true;
            }

            if (parent_track[curr] && !visited[parent_track[curr]]) {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = true;
                flag = true;
            }
        }
        
        if(flag) {
            ans++;
        }
    }
    
    return ans;
    
}

// Input:      
//           1
//         /   \
//       2      3
//     /  \      \
//    4    5      6
//        / \      \
//       7   8      9
//                    \
//                    10

// Target Node = 8
// Output: 7

// Explanation: If leaf with the value 
// 8 is set on fire. 
// After 1 sec: 5 is set on fire.
// After 2 sec: 2, 7 are set to fire.
// After 3 sec: 4, 1 are set to fire.
// After 4 sec: 3 is set to fire.
// After 5 sec: 6 is set to fire.
// After 6 sec: 9 is set to fire.
// After 7 sec: 10 is set to fire.
// It takes 7s to burn the complete tree.
