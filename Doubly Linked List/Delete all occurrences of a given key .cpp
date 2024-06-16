void deleteAllOccurOfX(struct Node** head_ref, int x) {
  Node* temp = *head_ref;
        
  while(temp != NULL && temp->data == x) {
    Node *del = temp;
    temp = temp -> next;
    temp -> prev = NULL;
    delete del;
  }
        
  *head_ref = temp;
  
  if(temp == NULL) return; // If the list became empty after deletions
  
  Node* pre = temp->prev;
        
  while(temp != NULL) {
    if(temp->data == x) {
      Node *del = temp;
                
      if(temp->next != NULL) {
        temp -> next ->prev = pre;
      }
      temp->prev->next = temp->next;
      temp = temp->next;
      delete del;
    }
    else {
      pre = temp;
      temp = temp->next;
    }
  }
}

// Input: 
// 2<->2<->10<->8<->4<->2<->5<->2
// 2
// Output: 
// 10<->8<->4<->5
