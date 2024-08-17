int solve(int n,int x,int y,int z,vector<int>&dp){
    if(n < 0){
        return INT_MIN; 
    }
    else if(n==0){
        return 0;
    }
    else if(dp[n]!=-1){
        return dp[n];
    }

    int t1 = solve(n-x,x,y,z,dp);
    int t2 = solve(n-y,x,y,z,dp);
    int t3 = solve(n-z,x,y,z,dp);
    return dp[n] = 1 + max({t1,t2,t3}); 
}
    
int maximizeTheCuts(int n, int x, int y, int z) {
    vector<int>dp(n+1,-1);
    int ans = solve(n,x,y,z,dp);
    return max(ans,0);
}

// Input: n = 5, x = 5, y = 3, z = 2
// Output: 2
// Explanation: Here total length is 5, and the cut lengths are 5, 3 and 2. We can make two segments of lengths 3 and 2.
