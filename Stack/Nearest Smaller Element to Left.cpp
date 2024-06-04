vector<int> leftSmaller(int n, int a[]){
  vector<int> v;
  stack <int> st;
 
  for(int i = 0; i < n ; i++) {
    while(!st.empty() && st.top () >= a[i]) {
      st.pop();
    }
    if(st.empty()) {
      v.push_back(-1);
    }
    else {
      v.push_back(st.top());
    }
    st.push(a[i]);
  }
  return v;
}

// Input : [4, 5, 2, 10, 8]
// Output : [-1, 4, -1, 2, 2]
