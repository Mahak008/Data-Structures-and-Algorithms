int findMinimumCost(string str) {
  if (str.length() % 2 != 0) {
    return -1;
  }

  stack<char> st;
  for (int i = 0; i < str.length(); i++) {
    if (st.empty() || (!st.empty() && str[i] == '{')) {
      st.push(str[i]);
    } else {
      if (st.top() == '{') {
        st.pop();
      } else {
        st.push(str[i]);
      }
    }
  }

  int a = 0, b = 0;
  while (!st.empty()) {
    if (st.top() == '{') {
      ++a;
    } else {
      ++b;
    }
    st.pop();
  }

  int ans = (a + 1) / 2 + (b + 1) / 2;
  return ans;
}

// Input: {}}{}}
// Output: 1
