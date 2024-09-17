// Leetcode - 884

vector<string> uncommonFromSentences(string s1, string s2) {
  unordered_map<string, int> words;
  string word = "";

  for (char c : s1) {
    if (c == ' ') {
      if (!word.empty()) {
        words[word]++;
        word = "";
      } 
    } else {
      word += c;
    }
  }

  if (!word.empty()) {
    words[word]++;
    word = "";
  }

  for (char c : s2) {
    if (c == ' ') {
      if (!word.empty()) {
        words[word]++;
        word = "";
      }
    } else {
      word += c;
    }
  }

  if (!word.empty()) {
    words[word]++;
    word = "";
  }

  vector<string> ans;
  for (auto it : words) {
    if (it.second == 1) {
      ans.push_back(it.first);
    }
  }

  return ans;
}

// Input: s1 = "this apple is sweet", s2 = "this apple is sour"
// Output: ["sweet","sour"]
