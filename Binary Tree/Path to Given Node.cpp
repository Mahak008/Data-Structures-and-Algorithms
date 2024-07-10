bool getPath(TreeNode* root, vector<int>&ans, int x) {
    if(!root) {
        return false;
    }
    
    ans.push_back(root->val);
    
    if(root->val == x) {
        return true;
    }
    
    if(getPath(root->left, ans, x) || getPath(root->right, ans, x)) {
        return true;
    }
    
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* root, int x) {
    vector<int>ans;
    getPath(root, ans, x);
    return ans;
}

// Input:
//            1
//          /   \
//         2     3
//        / \   / \
//       4   5 6   7 

// x = 5
// Output: 1, 2, 5
