// Leetcode - 404

bool isLeaf(TreeNode* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    int sum = 0;

    if (root->left != NULL && isLeaf(root->left)) {
        sum += root->left->val;
    }

    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

// Input: root = [3,9,20,null,null,15,7]
// Output: 24
// Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.
