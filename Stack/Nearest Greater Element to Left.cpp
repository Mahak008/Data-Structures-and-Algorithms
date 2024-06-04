for(int i = 0; i < n ; i++) {
    while(!st.empty() && st.top () <= a[i]) {
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

// Input: 4 8 5 2 25
// Output: -1 -1 8 5 -1
