vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target){
  vector<pair<int, int>>ans;
  Node* left = head;
  Node* right = head;
  
  while(right->next != NULL) {
    right = right->next;
  }
  
  while(left != NULL && right != NULL && left->data < right->data) {
    int sum = left->data + right->data;
    
    if(sum == target) {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    }
    else if(sum > target) {
      right = right->prev;
    }
    else {
      left = left->next;
    }
  }
  return ans;
}

// Input:  1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
// target = 7
// Output: (1, 6), (2,5)
