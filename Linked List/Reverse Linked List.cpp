ListNode* reverseList(ListNode* head) {
  ListNode* curr = head;
  ListNode* temp = head;
  ListNode* prev = nullptr;

  while(curr != nullptr) {
    temp = temp->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  head = prev;
  return head;
}

// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]
