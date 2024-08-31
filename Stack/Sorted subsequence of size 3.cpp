vector<int> find3Numbers(vector<int> &arr) {
  int n = arr.size();
        
  if(n < 3) {
    return {};
  }
        
  vector<int>smaller(n, -1), larger(n, -1);
  stack<int>s;
        
  for(int i = 0; i < n; i++) {
    while(!s.empty() && arr[s.top()] >= arr[i]) {
      s.pop();
    }
    if(!s.empty()) {
      smaller[i] = s.top();
    }
    s.push(i);
  }
        
  while(!s.empty()) {
    s.pop();
  }
        
  for(int i = n-1; i >= 0; i--) {
    while(!s.empty() && arr[s.top()] <= arr[i]) {
      s.pop();
    }
    if(!s.empty()) {
      larger[i] = s.top();
    }
    s.push(i);
  }
        
  for(int i = 0; i < n; i++) {
    if(smaller[i] != -1 && larger[i] != -1) {
      return {arr[smaller[i]], arr[i], arr[larger[i]]};
    }
  }
        
  return {};
}

// Input: arr = [1, 2, 1, 1, 3]
// Output: 1
// Explanation: A subsequence 1 2 3 exist.
