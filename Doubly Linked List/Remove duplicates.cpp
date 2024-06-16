// The Doubly Linked List is Sorted
Node * removeDuplicates(struct Node *head) {
  if (head == NULL) return NULL; // handle edge case of empty list
    Node* temp = head;
        
  while(temp != NULL) {
    Node* curr = temp->next;
      
    while(curr != NULL && curr->data == temp->data) {
      Node* del = curr;
              
      if(curr->next != NULL) {
        curr->next->prev = curr->prev;
      }
       
      if(curr->prev != NULL) {
        curr->prev->next = curr->next;
      }
        
      curr = curr->next;
      delete del;
    } 
      
    temp->next = curr;
     
    if (curr != NULL) {
      curr->prev = temp;
    }
      
    temp = temp->next;
  }
  return head;
}

// Input: 1 <-> 1 <-> 1 <-> 2 <-> 3 <-> 4
// Output: 1 <-> 2 <-> 3 <-> 4
