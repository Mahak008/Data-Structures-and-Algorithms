// Q - You are given the node to be deleted node. You will not be given access to the first node of head. All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.
// Approach - To delete a node in a singly-linked list without access to the head, you can take advantage of the fact that you can modify the given node itself. Since you have a reference to the node to be deleted, but not to the previous node, you can copy the data from the next node to the current node, and then delete the next node instead.
// Solution - 
void deleteNode(Node* node) {
  // Copy the data from the next node to the current node
  node -> data = node -> next -> data;
  
  // Save the next node to be deleted
  Node* temp = node -> next;

  // Link the current node to the node after the next node
  node -> next = node -> next -> next;
  
  // Delete the next node
  delete temp;
}
