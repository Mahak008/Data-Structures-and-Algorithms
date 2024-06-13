Node* reverseDLL(Node * head) {
  Node* temp = head;
  Node* curr = head;
  Node* pre = NULL;
        
  while(curr != NULL) {
    temp = temp -> next;
    curr -> next = pre;
    curr -> prev = temp;
    pre = curr;
    curr = temp;
  }
  head = pre;
  return head;
}
