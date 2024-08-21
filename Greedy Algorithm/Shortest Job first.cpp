long long solve(vector<int>& bt) {
  sort(bt.begin(), bt.end());
  int t = 0, wt = 0;
  int n = bt.size();
        
  for(int i = 0; i < n; i++) {
    wt += t; 
    t += bt[i]; 
  }
        
  return wt/n; 
}

// Input: 1, 2, 3, 4
// Output: 2
// Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.
