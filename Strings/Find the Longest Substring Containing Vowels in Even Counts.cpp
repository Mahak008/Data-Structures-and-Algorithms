// Leetcode - 1371

int findTheLongestSubstring(string s) {
  unordered_map<string, int> mp;
  vector <int> state(5, 0);
  string curr = "00000";

  mp[curr] = -1;
  int res = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      ++state[0];
    } else if (s[i] == 'e') {
      ++state[1];
    } else if (s[i] == 'i') {
      ++state[2];
    } else if (s[i] == 'o') {
      ++state[3];
    } else if (s[i] == 'u') {
      ++state[4];
    }

    curr = "";
    for (int j = 0; j < 5; ++j) {
      curr += to_string(state[j] % 2);
    }

    if (mp.find(curr) != mp.end()) {
      res = max(res,i - mp[curr]);
    } else {
      mp[curr] = i;
    }
  }

  return res;
}

// Alternate Method

int findTheLongestSubstring(string s) {
  unordered_map<string, int> mp;
  vector <int> state(5, 0);
  string curr = "00000";

  mp[curr] = -1;
  int res = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      state[0] ^= 1;
    } else if (s[i] == 'e') {
      state[1] ^= 1;
    } else if (s[i] == 'i') {
      state[2] ^= 1;
    } else if (s[i] == 'o') {
      state[3] ^= 1;
    } else if (s[i] == 'u') {
      state[4] ^= 1;
    }

    curr = "";
    for (int j = 0; j < 5; ++j) {
      curr += to_string(state[j] % 2);
    }

    if (mp.find(curr) != mp.end()) {
      res = max(res,i - mp[curr]);
    } else {
      mp[curr] = i;
    }
  }

  return res;
}

// Alternate Method

int findTheLongestSubstring(string s) {
  unordered_map<int, int> mp;
  int mask = 0;
  mp[mask] = -1;
  int res = 0;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') {
      mask ^= (1 << 0);
    } else if (s[i] == 'e') {
      mask ^= (1 << 1);
    } else if (s[i] == 'i') {
      mask ^= (1 << 2);
    } else if (s[i] == 'o') {
      mask ^= (1 << 3);
    } else if (s[i] == 'u') {
      mask ^= (1 << 4);
    }

    if (mp.find(mask) != mp.end()) {
      res = max(res,i - mp[mask]);
    } else {
      mp[mask] = i;
    }
  }

  return res;
}

// Input: s = "eleetminicoworoep"
// Output: 13
// Explanation: The longest substring is "leetminicowor" which contains two each of the vowels: e, i and o and zero of the vowels: a and u.
