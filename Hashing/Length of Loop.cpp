int countNodesinLoop(struct Node *head) {
    unordered_map<Node*, int> mp;
    Node*temp = head;
    int cnt = 1;
    
    while(temp != NULL) {
        if(mp.find(temp) != mp.end()) {
            int val = mp[temp];
            return cnt - val;
        }
        mp[temp] = cnt;
        cnt++;
        temp = temp->next;
    }
    return 0;
}
