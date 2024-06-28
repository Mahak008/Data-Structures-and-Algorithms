vector<string> subsequences(string str) {

  int n = str.length();
  vector<string> ans;

  for (int i = 0; i < (1 << n); i++) {
    string sub = "";

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        sub += str[j];
      }
    }

    if (!sub.empty()) {
      ans.push_back(sub);
    }
  }
  return ans;
}

// Input: abc
// Output: a ab abc ac b bc c
