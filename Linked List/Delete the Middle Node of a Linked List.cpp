ListNode* deleteMiddle(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* prev = nullptr;

    // Move fast pointer twice as fast as slow pointer
    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        prev = slow;
        slow = slow->next;
    }

    // Unlink the middle node
    if (prev != nullptr && slow != nullptr) {
        prev->next = slow->next;
        delete slow; // Free the memory of the middle node
    }

    return head;
}

// Input: 1, 3, 4, 7, 1, 2, 6
// Output: 1, 3, 4, 1, 2, 6
