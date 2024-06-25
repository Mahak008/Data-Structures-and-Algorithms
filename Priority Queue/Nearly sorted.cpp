vector <int> nearlySorted(int arr[], int num, int K){
  priority_queue<int, vector<int>, greater<int>> pq;
  vector<int> ans;
        
  for(int i = 0; i < num; i++) {
    pq.push(arr[i]);
    
    if(pq.size() > K) {
      ans.push_back(pq.top());
      pq.pop();
    }
  }
  
  while(!pq.empty()) {
    ans.push_back(pq.top());
    pq.pop();
  }
  return ans;
}

// Input:
// n = 7, k = 3
// arr[] = {6,5,3,2,8,10,9}
// Output: 2 3 5 6 8 9 10
