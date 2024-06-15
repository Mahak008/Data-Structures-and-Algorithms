bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    ListNode* secondHead = reverseList(slow->next);

    ListNode* firstHead = head;
    ListNode* newHead = secondHead;

    while (newHead != NULL) {
        if (firstHead->val != newHead->val) {
            return false;
        }
        firstHead = firstHead->next;
        newHead = newHead->next;
    }
    return true;
}
