bool checkPangram (string s) {
  set <char> ans;
  for(int i = 0; i < s.length(); i++) {
    if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
      s[i]=tolower(s[i]);
      ans.insert(s[i]);
    }
  }
  return ans.size() == 26;
}

// Input : "Bawds jog, flick quartz, vex nymph"
// Output: 1
