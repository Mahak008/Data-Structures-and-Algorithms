// Memoization
// Time - O(N)
// Space - O(N)

const int mod = 1e9 + 7;
int solve(int n, vector<int>&dp) {
    if(n <= 1) {
        return n;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    return dp[n] = (solve(n-1, dp) + solve(n-2, dp)) % mod;
}

int nthFibonacci(int n){
    if (n == 0) {
        return 0;
    }
    
    if (n == 1 || n == 2) {
        return 1;
    }

    vector<int>dp(n + 1, -1);
        
    return solve(n, dp);
}

// Input: n = 5
// Output: 5
