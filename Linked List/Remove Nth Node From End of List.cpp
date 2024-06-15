ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        temp = temp->next;
        cnt++;
    }

    if (head == NULL || (head->next == NULL && n == 1)) {
        return NULL;
    }

    if (cnt == n) {
        ListNode* del = head;
        head = head->next;
        delete del;
        return head;
    }

    int res = cnt - n;
    int k = 1;
    ListNode* rand = head;
    while (rand != NULL && k < res) {
        rand = rand->next;
        k++;
    }
    ListNode* del = rand->next;
    rand->next = rand->next->next;
    delete del;
    return head;
}

// Alternate Method

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL || (head->next == NULL && n == 1)) {
        return NULL;
    }

    ListNode* fast = head;
    ListNode* slow = head;

    int i = 0;
    while (i < n) {
        fast = fast->next;
        i++;
    }
    if (fast == NULL) {
        return head->next;
    }
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    ListNode* del = slow->next;
    slow->next = slow->next->next;
    delete del;
    return head;
}

// Input: 1, 2, 3, 4, 5 , n = 2
// Output: 1, 2, 3, 5
