//Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *head, int x) {
  Node *temp = new Node(x);
  temp -> next = head;
  head = temp;
  return head;
}
    
//Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *head, int x)  {
  Node *n = new Node(x);
  Node *temp = head;
  if (head == NULL) { // Handle the case when the linked list is empty
    return n;
  }
  while(temp->next != NULL) {
    temp = temp -> next;
  }
       
  temp->next = n;
  return head;
}
