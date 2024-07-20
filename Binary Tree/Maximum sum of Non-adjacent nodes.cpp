pair<int, int> solve(Node* root) {
    if(!root) {
        pair<int, int> p = make_pair(0, 0);
        return p;
    }    
    
    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);
    
    pair<int, int> res;
    
    res.first = root->data + left.second + right.second;
    res.second = max(left.first, left.second) + max(right.first, right.second);
    
    return res;
}

int getMaxSum(Node *root)  {
    pair<int, int> ans = solve(root);
    return max(ans.first, ans.second);
}

// Input:
//      11
//     /  \
//    1    2
// Output: 11
// Explanation: The maximum sum is sum of node 11.
