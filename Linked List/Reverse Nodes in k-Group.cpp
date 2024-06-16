ListNode* reverseList(ListNode* head) {
    ListNode* curr = head;
    ListNode* temp = head;
    ListNode* prev = nullptr;

    while (curr != nullptr) {
        temp = temp->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }

    head = prev;
    return head;
}
ListNode* getKNode(ListNode* temp, int k) {
    k -= 1;
    while (temp != NULL && k > 0) {
        k--;
        temp = temp->next;
    }
    return temp;
}
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* temp = head;
    ListNode* prev = NULL;

    while (temp != NULL) {
        ListNode* kNode = getKNode(temp, k);
        if (kNode == NULL) {
            if (prev) {
                prev->next = temp;
            }
            break;
        }

        ListNode* nextNode = kNode->next;
        kNode->next = NULL;
        reverseList(temp);
        if (temp == head) {
            head = kNode;
        } else {
            prev->next = kNode;
        }
        prev = temp;
        temp = nextNode;
    }
    return head;
}

// Input: 1, 2, 3, 4, 5, k = 2
// Output: 2, 1, 4, 3, 5
