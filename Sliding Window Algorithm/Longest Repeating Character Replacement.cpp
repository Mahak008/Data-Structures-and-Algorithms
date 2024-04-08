int longestRepeatingSubstring(string &s, int k) {
  map<char, int> mp;
  int l = 0, r = 0, maxFreq = 0, maxLen = 0;
  while (r < s.length()) {
    ++mp[s[r]];
    maxFreq = max(maxFreq, mp[s[r]]);
    if ((r - l + 1) - maxFreq > k) {
      --mp[s[l]];
      maxFreq = 0;
      for (auto i : mp) {
        if (maxFreq < i.second) {
          maxFreq = i.second;
        }
      }
      ++l;
    } else {
      maxLen = max(maxLen, (r - l + 1));
    }
    ++r;
  }
  return maxLen;
}
