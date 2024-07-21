Node* removeAllDuplicates(struct Node* head) {
  if(!head) 
    return NULL;
            
  unordered_map<int, int> mp;
  Node* temp = head;
        
  while(temp != NULL) {
    mp[temp->data]++;
    temp = temp->next;
  }
        
  temp = head;
  Node* dummy = new Node(-1);
  Node* curr = dummy;
        
  while(temp) {
    if(mp[temp->data] == 1) {
      curr->next = new Node(temp->data);
      curr = curr->next;
    }
    temp = temp->next;
  }
        
  return dummy->next;
}

// Input: 23->28->28->35->49->49->53->53
// Output: 23 35
