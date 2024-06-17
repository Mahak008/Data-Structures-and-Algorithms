Node *removeLoop(Node *head) {
  if (head == NULL || head->next == NULL) {
    return head; // No loop possible in an empty or single-node list
  }
  Node *fast = head;
  Node *slow = head;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    slow = slow->next;
    if (slow == fast) {
      break; // Loop Detected
    }
  }

  // If no loop detected, return the head as is
  if (fast == NULL || fast->next == NULL) {
    return head;
  }

  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }

  Node *loopNode = slow;
  while (fast->next != loopNode) {
    fast = fast->next;
  }
  fast->next = NULL;
  return head;
}
