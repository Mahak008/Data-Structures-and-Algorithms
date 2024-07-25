// Leetcode - 1038

void solve(TreeNode* root, int& sum) {
    if (!root) {
        return;
    }

    solve(root->right, sum);
    sum += root->val;
    root->val = sum;
    solve(root->left, sum);
}

TreeNode* bstToGst(TreeNode* root) {
    int sum = 0;
    solve(root, sum);
    return root;
}

//          4
//       /    \
//     1        6
//   /   \    /   \
// 0       2 5      7
//           \        \
//             3        8
