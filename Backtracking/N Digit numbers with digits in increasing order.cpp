void solve(int n, int start, string output, vector<int>& ans) {
    if(output.length() == n) {
        ans.push_back(stoi(output));
        return;
    }  
    
    for(int i = start; i <= 9; i++) {
        solve(n, i + 1, output + to_string(i), ans);
    }
}
 
vector<int> increasingNumbers(int n) {
    vector<int>ans;
    int start = 1;
    string output = "";
    
    if(n == 1) {
        for(int i = 0; i <= 9; i++) {
            ans.push_back(i);
        }
    }
    else {
        solve(n, start, output, ans);
    }
        
    return ans;
}

// Input: n = 1
// Output: 0 1 2 3 4 5 6 7 8 9
