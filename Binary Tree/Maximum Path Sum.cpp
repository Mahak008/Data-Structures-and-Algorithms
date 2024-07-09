// Leetcode - 124

int maxSum(TreeNode* root, int& maxi) {
    if (root == NULL) {
        return 0;
    }

    int lH = max(0, maxSum(root->left, maxi));
    int rH = max(0, maxSum(root->right, maxi));

    maxi = max(maxi, (root->val + lH + rH));

    return (root->val) + max(lH, rH);
}

int maxPathSum(TreeNode* root) {
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}

// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
 
