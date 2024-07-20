// Leetcode - 437

int solve(TreeNode* root, long long targetSum) {
    if (!root) {
        return 0;
    }

    int count = 0;
    if (targetSum == root->val) {
        count = 1;
    }

    count += solve(root->left, targetSum - root->val);
    count += solve(root->right, targetSum - root->val);

    return count;
}

int pathSum(TreeNode* root, int targetSum) {
    if (!root) {
        return 0;
    }

    int count = solve(root, targetSum);

    count += pathSum(root->left, targetSum);
    count += pathSum(root->right, targetSum);

    return count;
}

// Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
// Output: 3
// Explanation: The paths that sum to 8 are shown.
