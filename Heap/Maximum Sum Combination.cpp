vector<int> maxCombinations(int N, int K, vector<int> &A, vector<int> &B) {
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  vector<int> ans;
        
  //Max heap which contains tuple of the format (sum, (i, j)) i and j are the indices of the elements from array A and array B
  priority_queue<pair<int, pair<int, int>>>pq;
  set<pair<int, int>>st;
        
  pq.push(make_pair(A[N-1] + B[N-1], make_pair(N-1, N-1)));
  st.insert(make_pair(N-1, N-1));
        
  for(int x = 0; x < K; x++) {
    pair<int, pair<int, int>> temp = pq.top();
    pq.pop();
            
    ans.push_back(temp.first);
            
    int i = temp.second.first;
    int j = temp.second.second;
            
    int sum = A[i-1] + B[j];
    pair<int,int>temp1 = make_pair(i-1, j);
            
    if(st.find(temp1) == st.end()) {
      pq.push(make_pair(sum, make_pair(i-1, j)));
      st.insert(temp1);
    }
           
    sum = A[i] + B[j-1];
    temp1 = make_pair(i, j-1);
            
    if(st.find(temp1) == st.end()) {
      pq.push(make_pair(sum, make_pair(i, j-1)));
      st.insert(temp1);
    }
  }
        
  return ans;
}

// Input:
// N = 2
// K = 2
// A [ ] = {3, 2}
// B [ ] = {1, 4}
// Output: {7, 6}
// Explanation: 
// 7 -> (A : 3) + (B : 4)
// 6 -> (A : 2) + (B : 4)
