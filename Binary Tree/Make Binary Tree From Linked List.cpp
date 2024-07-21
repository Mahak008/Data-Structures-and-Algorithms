void convert(Node *head, TreeNode *&root) {
  if(!head)
    return;
            
  Node*temp = head;
  root = new TreeNode(temp->data);
        
  queue<TreeNode*>q;
  q.push(root);
        
  temp = temp->next;
        
  while(temp != NULL) {
    TreeNode*curr = q.front();
    q.pop();
            
    if(temp != NULL) {
      curr->left = new TreeNode(temp->data);
      q.push(curr->left);
      temp = temp->next;
    }
           
    if(temp != NULL) {
      curr->right = new TreeNode(temp->data);
      q.push(curr->right);
      temp = temp->next;
    }
  }
}

// Input: list = 1->2->3->4->5
// Output: 1 2 3 4 5
// Explanation: The tree would look like
//       1
//     /   \
//    2     3
//  /  \
// 4   5
// Now, the level order traversal of the above tree is 1 2 3 4 5.
