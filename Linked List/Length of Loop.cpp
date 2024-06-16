int countNodesinLoop(struct Node *head) {
    Node* fast = head;
    Node* slow = head;
    int cnt  = 0;
    
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;

        if (fast == slow) {
            cnt = 1;
            Node* temp = slow;
            while (temp->next != slow) {
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
    }
    return 0;
}
