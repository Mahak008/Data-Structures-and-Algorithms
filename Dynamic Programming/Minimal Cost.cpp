int solve(vector<int>& arr, int &k, vector<int> &dp, int n) {
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        return abs(arr[1] - arr[0]);
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int ans = INT_MAX;
    
    for(int i = 1; i <= k; i++) {
        if(n - i >= 0) {
            int sum = solve(arr, k, dp, n-i) + abs(arr[n] - arr[n-i]);
            ans = min(sum, ans);
        }
    }
    
    dp[n] = ans;
    return dp[n];
}

int minimizeCost(vector<int>& arr, int& k) {
    int n = arr.size();
    vector<int>dp(n, -1);
    
    return solve(arr, k, dp, n-1);
}

// Input: k = 3, arr[]= [10, 30, 40, 50, 20]
// Output: 30
// Explanation: Geek will follow the path 1->2->5, the total cost would be | 10-30| + |30-20| = 30, which is minimum
