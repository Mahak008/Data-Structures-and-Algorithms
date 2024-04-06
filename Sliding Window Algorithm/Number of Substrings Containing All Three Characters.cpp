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
int countSubstring(string s) {
  int ch[3] = {-1, -1, -1};
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    ch[s[i] - 'a'] = i;
    if (ch[0] != -1 && ch[1] != -1 && ch[2] != -1) {
      cnt += (1 + min({ch[0], ch[1], ch[2]}));
    }
  }
  return cnt;
}

// Input: s = "abcabc"
// Output: 10
// Explanation:"abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc". 
