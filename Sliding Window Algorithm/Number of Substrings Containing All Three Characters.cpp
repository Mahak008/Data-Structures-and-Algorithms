int countSubstring(string s) {
  int count = 0;
  int n = s.length();
  for (int i = 0; i < n; i++) {
    set<char> st;
    for (int j = i; j < n; j++) {
      st.insert(s[j]);
      if (st.size() == 3) {
        count += (n - j);
        break;
      }
    }
  }
  return count;
}

// Optimised Approach
