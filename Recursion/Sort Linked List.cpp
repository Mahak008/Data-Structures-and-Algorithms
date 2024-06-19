// Merge Sort on Linked List 

ListNode* middleNode(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = NULL;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    return prev;
}

ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(-1);
    ListNode* temp = dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            temp->next = l1;
            temp = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            temp = l2;
            l2 = l2->next;
        }
    }

    if (l1)
        temp->next = l1;
    else
        temp->next = l2;

    return dummy->next;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* mid = middleNode(head);

    ListNode* rightHead = mid->next;
    mid->next = NULL;

    ListNode* leftHead = head;

    leftHead = sortList(leftHead);
    rightHead = sortList(rightHead);

    return merge2Lists(leftHead, rightHead);
}
