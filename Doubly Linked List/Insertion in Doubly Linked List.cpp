void addNode(Node *head, int pos, int data) {
   Node *n = new Node(data);
   
    // Insertion at first node
    if(pos == 0) {
        // If the list is empty
        if(head == NULL) {
           head = n;
           return;
        }
        n -> next = head;
        head -> prev = n;
       head = n;
       return;
    }
   
    int cnt = 0;
    Node *temp = head;
    
    while(cnt < pos && temp -> next != NULL) {
       temp = temp -> next;
       cnt++;
    }
   
    // Insertion at last node
    if(temp -> next == NULL) {
        n -> next = NULL;
        temp -> next = n;
        n -> prev = temp;
        return;
    }
   
    // Insertion in Between two nodes
    n -> next = temp -> next;
    temp -> next = n;
    n -> prev = temp;
    
    if(n -> next != NULL) {
        n -> next -> prev = n;
    }
}
