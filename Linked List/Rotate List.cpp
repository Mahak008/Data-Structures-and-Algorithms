ListNode* rotateRight(ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int l = count(head);

    k = k % l;
    if (k == 0)
        return head;

    while (k--) {
        ListNode* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        ListNode* last = temp->next;
        temp->next = NULL;
        last->next = head;
        head = last;
    }
    return head;
}

// Input: 1, 2, 3, 4, 5, k = 2
// Output: 4, 5, 1, 2, 3
