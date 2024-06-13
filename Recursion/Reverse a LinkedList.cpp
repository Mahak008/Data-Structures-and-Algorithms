ListNode* reverseList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    ListNode* newHead = reverseList(head->next);
    ListNode* temp = head->next;
    temp->next = head;
    head->next = NULL;
    return newHead;
}
