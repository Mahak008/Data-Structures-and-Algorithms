Node* merge(Node* l1, Node* l2) {
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    
    while(l1 != NULL && l2 != NULL) {
        if(l1->data < l2->data) {
            res->bottom = l1;
            res = l1;
            l1 = l1->bottom;
        } else {
            res->bottom = l2;
            res = l2;
            l2 = l2->bottom;
        }
        res->next = NULL;
    }
    
    if(l1) res->bottom = l1;
    else res->bottom = l2;
    
    if(dummyNode->bottom) {
        dummyNode->bottom->next = NULL;
    }
    return dummyNode->bottom;
}
Node *flatten(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }
    Node* mergeHead = flatten(head->next);
    head = merge(head, mergeHead);
    return head;
}

// Input:
// 5 -> 10 -> 19 -> 28
// |     |     |     | 
// 7     20    22   35
// |           |     | 
// 8          50    40
// |                 | 
// 30               45
// Output:  5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50.
