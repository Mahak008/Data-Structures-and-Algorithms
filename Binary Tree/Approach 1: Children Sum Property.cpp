// Top Down Approach - 
// If the sum of the children's values > root's value, root = sum of child
// If the sum of the children's values < root's value, leftChild = rightChild = value of root

// Bottom-Up Correction:
// After updating the node and its children, the function recursively calls itself on the left and right subtrees.
// Once the recursion unwinds (returns back up the call stack), the values of the children nodes are summed and assigned back to the node.

void convertTree(Node* root) {
    if(!root) return;

    int child = 0;

    if(root->left) {
        child += root->left->data;
    }

    if(root->right) {
        child += root->right->data;
    }

    if(child >= root->data) {
        root->data = child;
    } else {
        if(root->left) {
            root->left->data = root->data;
        }
        if(root->right) {
            root->right->data = root->data;
        }
    }

    convertTree(root->left);
    convertTree(root->right);

    int total = 0;
    if(root->left) {
        total += root->left->data;
    }
    if(root->right) {
        total += root->right->data;
    }

    if(root->left || root->right) {
        root->data = total;
    }
}

// Input:
//           50
//        /      \
//       7        2
//     /   \    /   \
//    3     5  1    30

// Output:
//             200
//        /          \
//       100         100
//     /     \     /     \
//    50      50  50      50

