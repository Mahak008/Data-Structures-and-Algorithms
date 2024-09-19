string reverseWords(string str) {
  vector<string>word;
  int i = 0;
  int n = str.length();
  string st = "";
        
  while(i < n) {
    if(str[i] != '.') {
      st += str[i];
    } else {
      word.push_back(st);
      st = "";
    }
    i++;
  }
  
  word.push_back(st);
  reverse(word.begin(), word.end());
  string ans = "";
        
  for(const string &s : word) {
    ans += s + '.';
  }
        
  return ans.substr(0, n);
}

// Input: i.like.this.program.very.much
// Output: much.very.program.this.like.i
