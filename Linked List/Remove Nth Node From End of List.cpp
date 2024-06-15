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

// Input: 1, 2, 3, 4, 5 , n = 2
// Output: 1, 2, 3, 5
