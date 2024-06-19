ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;
    
    for (int i = 0; i < lists.size(); i++) {
        if (lists[i]) {
            pq.push({lists[i]->val, lists[i]});
        }
    }
    
    ListNode* dummyNode = new ListNode(-1);
    ListNode* temp = dummyNode;

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();

        if (it.second->next) {
            pq.push({it.second->next->val, it.second->next});
        }

        temp->next = it.second;
        temp = temp->next;
    }
    return dummyNode->next;
}

// Input: lists = [[1,4,5],[1,3,4],[2,6]]
// Output: [1,1,2,3,4,4,5,6]
