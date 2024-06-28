void solve(string s, string output, int index, vector<string>& ans) {
  int n = s.length();

  if (index == n - 1) {
    output += s[index];
    ans.push_back(output);
    return;
  }

  // Include the current character with a space
  solve(s, output + s[index] + " ", index + 1, ans);

  // Include the current character without a space
  output += s[index];
  solve(s, output, index + 1, ans);
}

vector<string> permutation(string s) {
  vector<string> ans;
  string output = "";
  int index = 0;
  
  solve(s, output, index, ans);
  return ans;
}

// Input: "ABC"
// Output: (A B C)(A BC)(AB C)(ABC)
