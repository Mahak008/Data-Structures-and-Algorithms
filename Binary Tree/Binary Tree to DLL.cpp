Node * bToDLL(Node *root) {
    if(root == NULL) {
        return NULL;
    }
    
    Node* curr = root;
    Node* head = NULL;  // Head of the DLL
    Node* prev = NULL;  // Previous processed node in DLL
    
    while(curr != NULL) {
        if(curr->left == NULL) {
            // If left child is NULL, process the current node
            if(head == NULL) {
                head = curr;  // Set head if it's the first node
            }
            if(prev != NULL) {
                prev->right = curr;
                curr->left = prev;
            }
            prev = curr;
            curr = curr->right;  // Move to the right child
        } else {
            // Find the inorder predecessor of current
            Node* pre = curr->left;
            while(pre->right != NULL && pre->right != curr) {
                pre = pre->right;
            }

            // Make current as the right child of its inorder predecessor
            if(pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            } else {
                // Revert the changes made in the tree to restore original tree
                pre->right = NULL;
                if(prev != NULL) {
                    prev->right = curr;
                    curr->left = prev;
                } else {
                    head = curr;
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    return head;
}

// Input:
//        10
//       /   \
//      20   30
//    /   \
//   40   60

// Output:
// 40 20 60 10 30 
// 30 10 60 20 40

// Explanation:  DLL would be 40<=>20<=>60<=>10<=>30.
