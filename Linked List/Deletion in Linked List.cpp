Node* deleteNode(Node *head,int x) {
    Node *temp = head;
    if (head == NULL || head -> next == NULL) {
        return NULL;
    }
    
    if (x == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    
    int cnt = 1;
    while(temp -> next != NULL && cnt != x-1) {
        temp = temp -> next;
        cnt++;
    }
    
    Node * del = temp -> next;
    temp -> next = temp -> next -> next;
    
    delete del;
    return head;
}
