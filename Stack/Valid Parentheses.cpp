bool isValid(string s) {
  int len = s.length();
  stack<int> st;
  for (int i = 0; i < len; i++) {
    if (st.empty()) {
      if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
        st.push(s[i]);
      } else {
        return false;
      }
    } else {
      if ((st.top() == '(' && s[i] == ')') ||
          (st.top() == '{' && s[i] == '}') ||
          (st.top() == '[' && s[i] == ']')) {
        st.pop();
      } else {
        st.push(s[i]);
      }
    }
  }
  if (st.empty()) {
    return true;
  }
  return false;
}

// Input: s = "()[]{}"
// Output: true
