vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
priority_queue <int, vector<int>, greater<int>> pq;
vector<int> ans;
        
  for(int i = 0; i < K; i++) {
    for(int j = 0; j < arr[0].size(); j++) {
      pq.push(arr[i][j]);
    } 
  }
        
  while(!pq.empty()) {
    int x = pq.top();
    ans.push_back(x);
    pq.pop();
  } 
        
  return ans; 
}

// Input: k = 3, arr[][] = {{1,2,3},{4,5,6},{7,8,9}}
// Output: 1 2 3 4 5 6 7 8 9
