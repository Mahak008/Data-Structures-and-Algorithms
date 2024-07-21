int verticalWidth(Node* root) {
  if(!root) {
    return 0;
  }
        
  set<int>s;
  queue<pair<Node*, int>>q;
  q.push({root,0});
        
  while(!q.empty()) {
    Node* curr = q.front().first;
    int x = q.front().second;
    s.insert(x);
    q.pop();
            
    if(curr->left) {
      q.push({curr->left, x - 1});
    }
           
    if(curr->right) {
      q.push({curr->right, x + 1});
    }
  }
  
  return s.size();
}

// Input:
//          1
//        /    \
//       2      3
//      / \    /  \
//     4   5  6   7
//             \   \
//              8   9
// Output: 6
