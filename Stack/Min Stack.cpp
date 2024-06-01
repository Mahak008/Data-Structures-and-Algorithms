int getMin() {
  stack <int> s2;
  int m = INT_MAX;
  
  while(!s.empty()) {
    if(m > s.top()) {
      m = s.top();
    }
    s2.push(s.top());
    s.pop();
  }
  while(!s2.empty()) {
    s.push(s2.top());
    s2.pop();
  }
  return m;
}

// Alternate Approach
