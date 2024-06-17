bool isCircular(Node *head) {
  if (head == NULL) {
    return true;
  }

  Node *slow = head;
  Node *fast = head;

  while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;

    // Check if the two pointers meet
    if (slow == fast) {
      // A cycle is detected, now check if it includes the head
      Node *temp = slow;
      while (temp->next != head && temp->next != slow) {
        temp = temp->next;
      }
      return temp->next == head;
    }
  }

  // If fast reaches NULL, there is no cycle
  return false;
}

// Input: 1 2 3 4 5 6 7
// Output: False
