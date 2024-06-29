void solve(int zero, int one, int n, string output, vector<string>& ans) {
    if(n == 0) {
        ans.push_back(output);
        return;
    }
    
    string op1 = output;
    op1 += '1';
    solve(zero, one + 1, n - 1, op1, ans);

    if(one > zero) {
        string op2 = output;
        op2 += '0';
        solve(zero + 1, one, n - 1, op2, ans);
    }
    
}
vector<string> NBitBinary(int n) {
    vector<string>ans;
	  string output = "";
	  int zero = 0, one = 0;
	    
	  solve(zero, one, n, output, ans);
	    
	  return ans;
}

// Input:  n = 3
// Output: "111", "110", "101"
