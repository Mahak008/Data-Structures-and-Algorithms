Node* deleteNode(Node *head,int x) {
    Node *temp = head;

    // If the list is empty
    if (head == NULL) {
        return NULL;
    }

    // Delete first node
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
    temp -> next = del -> next;
    
    delete del;
    return head;
}
