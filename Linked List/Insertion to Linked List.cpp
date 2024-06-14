//Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x) {
  Node *n = new Node(x);
 
  // If the list is empty
  if(head == NULL) {
    head = n;
    return head;
  }
  
  n -> next = head;
  head = n;
  return head;
}

//Function to insert a node at the position of the linked list.
Node *insertAtPos(Node *head, int pos, int x) {
  Node *n = new Node(x);
  Node *temp = head;
  int cnt = 1;
  
  while(cnt < pos && temp -> next != NULL) {
    temp = temp -> next;
    cnt++;
  }

  n -> next = temp -> next;
  temp -> next = n;
  return head;
}
    
//Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)  {
  Node *n = new Node(x);
  Node *temp = head;
  
  if (head == NULL) { // Handle the case when the linked list is empty
    return n;
  }
  
  while(temp -> next != NULL) {
    temp = temp -> next;
  }
       
  temp -> next = n;
  return head;
}
