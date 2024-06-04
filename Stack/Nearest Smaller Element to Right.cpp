vector<int> help_classmate(vector<int> arr, int n) { 
  stack <int> st;
  vector <int> v;
  for(int i = n-1; i >= 0; i--) {
    while(!st.empty() && st.top() >= arr[i]) {
      st.pop();
    }
    if(st.empty()) {
      v.emplace_back(-1);
    }
    else {
      v.emplace_back(st.top());
    }
    st.push(arr[i]);
  }
  reverse(v.begin(), v.end());
  return v;
} 

// Input: 3, 8, 5, 2, 25
// Output: 2 5 2 -1 -1
