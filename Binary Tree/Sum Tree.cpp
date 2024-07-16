int sum (Node*root) {
    if(root == NULL) return 0;
    
    return sum(root->left) + root->data + sum(root->right);
    
}

bool isSumTree(Node* root) {
    
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return true;
    }
    
    int leftSum = sum(root->left);
    int rightSum = sum(root->right);

    if (root->data == leftSum + rightSum) {
        if(isSumTree(root->left) && isSumTree(root->right)) {
            return true;
        }
    }

    return false;
}

// Input:

//           10
//         /    \
//       20      30
//     /   \ 
//    10    10

// Output: 0
