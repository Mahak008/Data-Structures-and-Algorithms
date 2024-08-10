// Leetcode - 509

const long long MOD = 1e9+7;

// Memoization
// Time - O(N)
// Space - O(N)

long long solve(vector<long long> &dp, int n) {
    if(n == 0) {
        return 0;
    }
    
    if(n == 1 || n == 2) {
        return 1;
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    dp[n] = (solve(dp, n-1) + solve(dp, n-2)) % MOD;
    return dp[n];
}

long long int topDown(int n) {
    if(n < 0) {
        return 0; 
    }
    
    vector<long long>dp(n+1, -1);
        
    long long ans = solve(dp, n);
        
    return ans;
}

// Tabulation

long long int bottomUp(int n) {
    if(n < 0) {
        return 0;
    }
    
    if(n == 0) {
        return 0;
    }
    
    if(n == 1){
        return 1;
    }
    
    long long a = 0;
    long long b = 1;
    long long sum = 0;
        
    for(int i = 2; i <= n; i++) {
        sum = (a + b) % MOD;
        a = b;
        b = sum;
    }
        
    return sum;
}

// Input: n = 5
// Output: 5
