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

stack <long long> st;
long long mini = INT_MAX;

void push(int val) {
  if(st.empty()) {
    mini = val;
    st.push(val);
  }
  else{
    if(val < mini) {
      st.push(2LL * val - mini);
      mini = val;
    }
    else {
      st.push(val);
    }
  } 
}
    
void pop() {
  if(st.empty()) {
    cout << -1;
    return;
  }
  long long top = st.top();
  st.pop();
        
  if(top < mini) {
    mini = 2 * mini - top; // Revert mini to previous minimum
  }
}
    
int top() {
  if(st.empty()) return -1; // Handle empty stack
  long long top = st.top();
  if(top < mini) {
    return mini; // Return the current minimum value
  }
  return top;
}
    
int getMin() {
  if(st.empty()) return -1; // Handle empty stack
  return mini;
}
