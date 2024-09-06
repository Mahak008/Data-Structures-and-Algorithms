// Leetcode - 3217

ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    set<int> st;
    for (const int& i : nums) {
        st.insert(i);
    }

    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* temp = dummy;

    while (temp->next != NULL) {
        int x = temp->next->val;

        if (st.find(x) != st.end()) {
            ListNode* del = temp->next;
            temp->next = temp->next->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }

    return dummy->next;
}

// Input: nums = [1,2,3], head = [1,2,3,4,5]
// Output: [4,5]
