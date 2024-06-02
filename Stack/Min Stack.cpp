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
 
// Alternate Approach - 
// Time Complexity: O(1)
// Space Complexity: O(2N)
  
stack < pair < int, int >> st;
int mini;
void push(int val) {
  if(st.empty()) {
    mini = val;
  }
  else {
    mini = min(st.top().second, val);
  }
  st.push({val, mini});
}
    
void pop() {
  st.pop();
}
    
int top() {
  return st.top().first;
}
    
int getMin() {
  return st.top().second;
}

// Alternate Approach
// Time Complexity: O(1)
// Space Complexity: O(N)


  
