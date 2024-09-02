int solve(int W, vector<int>& wt, vector<int>& val, int n) {
  if(n == 0 || W == 0) {
    return 0;
  }
        
  if(wt[n-1] <= W) {
    return max(val[n-1] + solve(W - wt[n-1], wt, val, n-1), solve(W, wt, val, n-1));
  }
        
  return solve(W, wt, val, n-1);
}
    
int knapSack(int W, vector<int>& wt, vector<int>& val) {
  int n = wt.size();
  return solve(W, wt, val, n);
}

// Input: W = 4, val[] = {1,2,3}, wt[] = {4,5,1}
// Output: 3
// Explanation: Choose the last item that weighs 1 unit and holds a value of 3. 
