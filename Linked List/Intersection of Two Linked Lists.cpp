int getCount(ListNode* head) {
    ListNode* temp = head;
    int cnt = 0;
    while (temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}
ListNode* collisionHead(ListNode* headA, ListNode* headB, int n) {
    while (n) {
        headB = headB->next;
        n--;
    }
    while (headA != headB) {
        headA = headA->next;
        headB = headB->next;
    }
    return headA;
}
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    int n1 = getCount(headA);
    int n2 = getCount(headB);

    if (n1 < n2) {
        return collisionHead(headA, headB, n2 - n1);
    } else {
        return collisionHead(headB, headA, n1 - n2);
    }

    return NULL;
}
// Space - O(1)
// Time - O(n1) + O(2n2)

// Most Optimal Approach
ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* temp1 = headA;
    ListNode* temp2 = headB;

    while (temp1 != temp2) {
        if (temp1 == NULL) {
            temp1 = headB;
        } else {
            temp1 = temp1->next;
        }

        if (temp2 == NULL) {
            temp2 = headA;
        } else {
            temp2 = temp2->next;
        }
    }
    if (temp1 == temp2) {
        return temp1;
    }
    return NULL;
}

// Space - O(1)
// Time - O(1)
