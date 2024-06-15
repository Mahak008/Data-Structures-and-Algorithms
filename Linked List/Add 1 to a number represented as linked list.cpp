Node* addOne(Node *head) {
  Node* newHead = reverseList(head);
  Node* temp = newHead;
        
  int carry = 1;
  int sum = 0;
        
  while(temp != NULL) {
    sum = carry + temp->data;
    temp->data = sum%10;
    carry = sum/10;
    temp = temp->next;
            
    if(carry == 0) 
      break;
  }
        
  Node* ans = reverseList(newHead);
  
  if(carry) {
    Node* newNode = new Node(carry);
    newNode->next = ans;
    ans = newNode;
  }        
  return ans;
}

// Without Reversal

// LinkedList: 4 -> 5 -> 6
// Output: 457
