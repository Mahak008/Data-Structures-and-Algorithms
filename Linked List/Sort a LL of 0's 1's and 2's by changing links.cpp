Node* segregate(Node *head) {
  if (!head || !head->next) return head;
    
  Node* temp = head;
      
  Node* zeroHead = new Node(-1);
  Node* oneHead = new Node(-1);
  Node* twoHead = new Node(-1);
      
  Node* zero = zeroHead;
  Node* one = oneHead;
  Node* two = twoHead;
   
  while(temp != NULL) {
    if(temp->data == 0) {
      zero->next = temp;
      zero = zero->next;
    }
    else if(temp->data == 1) {
      one->next = temp;
      one = one->next;
    }
    else if(temp->data == 2) {
      two->next = temp;
      two = two->next;
    }
    temp = temp->next;
  }
       
  two->next = NULL;
   
  // Connecting the first 1 node to last of zero node
  if (oneHead->next) {
    zero->next = oneHead->next;
  } else if(twoHead->next) {
    zero->next = twoHead->next;
  } else {
    zero->next = NULL;
  }
  
  if(twoHead->next) {
    one->next = twoHead->next;
  } else {
    one->next = NULL;
  }
       
  if(zeroHead->next) {
    head = zeroHead->next;
  } else if(oneHead->next) {
    head = oneHead->next;
  } else {
    head = twoHead->next;
  }
      
  delete zeroHead;
  delete oneHead;
  delete twoHead;
       
  return head;
}

// Input: 1, 2, 2, 1, 2, 0, 2, 2 
// Output: 0 1 1 2 2 2 2 2
