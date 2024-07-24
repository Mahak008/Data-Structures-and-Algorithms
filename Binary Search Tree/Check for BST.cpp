bool isBSTUtil(Node* node, int min, int max) {
    if (node == NULL) {
        return true;
    }

    // Check if the node's data is within the valid range
    if (node->data < min || node->data > max) {
        return false;
    }

    // Recursively check the subtrees, tightening the min/max constraints
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Input:
//    2
//  /    \
// 1      3
//         \
//          5
// Output: true 
