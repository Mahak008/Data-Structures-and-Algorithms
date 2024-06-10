queue<int> modifyQueue(queue<int> q, int k) {
  stack <int> st;
  int m = k;
  int n = q.size();
        
  if (k > q.size()) {
    return q; // If k is larger than the queue size, return the original queue
  }
         
  while(m > 0) {
    st.push(q.front());
    q.pop();
    m--;
  }
  
  while(!st.empty()) {
    q.push(st.top());
    st.pop();
  }
       
  int x = n - k;
  while(x > 0) {
    q.push(q.front());
    q.pop();
    x--;
  }
  return q;
}

// Input: k = 3, 1 2 3 4 5
// Output: 3 2 1 4 5
