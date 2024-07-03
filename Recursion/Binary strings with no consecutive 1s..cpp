void solve(int n, string output, vector<string> &ans) {
  if (n == 0) {
    ans.push_back(output);
    return;
  }

  solve(n - 1, output + '0', ans);

  if (output.empty() || output.back() == '0') {
    solve(n - 1, output + '1', ans);
  }
}

vector<string> generateString(int N) {
  vector<string> ans;
  string output = "";
  solve(N, output, ans);
  return ans;
}

// Input: 4
// Output: 0000 0001 0010 0100 0101 1000 1001 1010 
