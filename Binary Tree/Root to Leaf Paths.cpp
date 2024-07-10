void solve(Node* root, vector<int>output, vector<vector<int>>& ans) {
    if(root == NULL) {
        return;
    }
    
    output.push_back(root->data);
    
    if(!root->left && !root->right) {
        ans.push_back(output);
    }
    else {
        solve(root->left, output, ans);
        solve(root->right, output, ans);
    }
    
    output.pop_back();
}
    
vector<vector<int>> Paths(Node* root) {
    vector<vector<int>> ans;
    vector<int>output;
    
    solve(root, output, ans);
    return ans;
}

// Input:
//          10
//        /    \
//       20    30
//      /  \
//     40   60
// Output: 
// 10 20 40 
// 10 20 60 
// 10 30 
