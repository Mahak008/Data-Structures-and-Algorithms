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

// Alternate Method
int count(Node* head) {
    int cnt = 0;
    Node* temp = head;
    
    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    
    return cnt;
}

Node* findLast(Node* head) {
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    return temp;
}

Node* rotate(Node* head, int k) {
    int l = count(head);
    
    if (head == NULL || head->next == NULL || k == 0 || k == l) {
        return head;
    }
    
    Node* curr = head;
        
    for(int i = 1; i < k; i++) {
        curr = curr->next;
    }
        
    Node* newHead = curr->next;
    Node* lastNode = findLast(newHead);
    
    curr->next = NULL;
    lastNode->next = head;
    
    return newHead;
}

// Input: 1, 2, 3, 4, 5, k = 2
// Output: 4, 5, 1, 2, 3
