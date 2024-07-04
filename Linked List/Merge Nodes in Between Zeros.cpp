ListNode* mergeNodes(ListNode* head) {
    ListNode* temp = head->next;
    ListNode* dummy = new ListNode(-1);
    ListNode* res = dummy;
    int sum = 0;

    while (temp != NULL) {
        if (temp->val != 0) {
            sum += (temp->val);
            temp = temp->next;
        } else {
            if (sum != 0) {
                ListNode* newNode = new ListNode(sum);
                res->next = newNode;
                res = res->next;
            }
            sum = 0;
            temp = temp->next;
        }
    }
    return dummy->next;
}

// Input: head = [0,3,1,0,4,5,2,0]
// Output: [4,11]
