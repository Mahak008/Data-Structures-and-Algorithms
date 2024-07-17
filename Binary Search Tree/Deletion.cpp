TreeNode* findLastRight(TreeNode* root) {
    while(root->right) {
        root = root->right;
    }
    return root;
}

TreeNode* helper(TreeNode* root) {
    if(!root) return NULL;
    if(!root->left) return root->right;
    if(!root->right) return root->left;

    TreeNode* rightChild = root->right;
    TreeNode* lastRight = findLastRight(root->left);
    lastRight->right = rightChild;

    return root->left;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return NULL;

    if (root->val == key) {
        return helper(root);
    }

    TreeNode* curr = root;

    while (curr) {
        if (curr->val > key) {
            if (curr->left && curr->left->val == key) {
                curr->left = helper(curr->left);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right && curr->right->val == key) {
                curr->right = helper(curr->right);
                break;
            } else {
                curr = curr->right;
            }
        }
    }

    return root;
}

// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,2,6,null,4,null,7]

// Another Approach

TreeNode* findLastLeft(TreeNode* root) {
    while (root->left) {
        root = root->left;
    }
    return root;
}

TreeNode* helper(TreeNode* root) {
    if (!root)
        return NULL;
    if (!root->left)
        return root->right;
    if (!root->right)
        return root->left;

    TreeNode* leftChild = root->left;
    TreeNode* lastLeft = findLastLeft(root->right);
    lastLeft->left = leftChild;

    return root->right;
}
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root)
        return NULL;

    if (root->val == key) {
        return helper(root);
    }

    TreeNode* curr = root;

    while (curr) {
        if (curr->val > key) {
            if (curr->left && curr->left->val == key) {
                curr->left = helper(curr->left);
                break;
            } else {
                curr = curr->left;
            }
        } else {
            if (curr->right && curr->right->val == key) {
                curr->right = helper(curr->right);
                break;
            } else {
                curr = curr->right;
            }
        }
    }

    return root;
}

// Input: root = [5,3,6,2,4,null,7], key = 3
// Output: [5,4,6,2,null,null,7]
