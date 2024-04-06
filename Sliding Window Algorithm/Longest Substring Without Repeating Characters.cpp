int lengthOfLongestSubstring(string s) {
  int l = 0, r = 0, maxLen = 0;
  map <char, int> mp;
  while(r < s.length()) {
    mp[s[r]]++;
    while(mp[s[r]] > 1) {
      mp[s[l]]--;
      ++l;
    }
    maxLen = max(maxLen, (r-l+1));
    ++r;
  }
  return maxLen;      
}

