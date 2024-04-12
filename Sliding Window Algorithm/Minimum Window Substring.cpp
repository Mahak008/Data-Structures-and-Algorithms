string minSubstring(string &s, string &t)
{
    // Write your code here.
    int x = 0, len, minLen = INT_MAX, start = -1, end = -1;
        unordered_map <char, int> mp;
        while(x < t.length()) {
            ++mp[t[x]];
            ++x;
        }
        int cnt = mp.size();
        int l = 0, r = 0;
        while(r < s.length()) {
            if(mp.find(s[r]) != mp.end()) {
                --mp[s[r]];
                if(mp[s[r]] == 0) {
                    --cnt;
                }
            }
            while(cnt == 0) {
                if (r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                    end = r;
                }
                if (mp.find(s[l]) != mp.end()) {
                    ++mp[s[l]];
                    if (mp[s[l]] > 0) {
                        ++cnt;
                    }
                }
                ++l;
            }
            ++r;
        }
        return (start == -1 || end == -1) ? "" : s.substr(start, end - start + 1);
}

// Input: s = "ADOBECODEBANC", t = "ABC"
// Output: "BANC"
// Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.
