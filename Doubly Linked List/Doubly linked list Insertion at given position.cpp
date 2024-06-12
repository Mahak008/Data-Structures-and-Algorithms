void addNode(Node *head, int pos, int data) {
  Node *n = new Node(data);
  Node *temp = head;
   
  int cnt = 0;
   
  while(cnt < pos && temp -> next != NULL) {
    temp = temp -> next;
    cnt++;
  }
   
  n -> next = temp -> next;
  if (temp->next != NULL) {
    temp->next->prev = n;
  }
     
  temp -> next = n;
  n -> prev = temp;
}
