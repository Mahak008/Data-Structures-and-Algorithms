int getCount(struct Node* head){
  int cnt = 1;
  Node * temp = head;
  
  while(temp->next != NULL) {
    temp = temp -> next;
    ++cnt;
  }
  return cnt;  
}
