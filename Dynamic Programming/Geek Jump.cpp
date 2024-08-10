int solve(vector<int> & height, int n, vector<int> &dp) {
    if(n == 0) {
        return 0;
    }
    
    if(n == 1) {
        return abs(height[1] - height[0]);
    }
    
    if(dp[n] != -1) {
        return dp[n];
    }
    
    int first, second;
    
    if(n-1 >= 0) {
        first = abs(height[n] - height[n-1]) + solve(height, n-1, dp);
    }
    
    if(n-2 >= 0) {
        second = abs(height[n] - height[n-2]) + solve(height, n-2, dp); 
    }
    
    dp[n] = min(first, second);
    return dp[n];
}

int minimumEnergy(vector<int>& height, int n) {
    if(n == 0) {
        return 0;
    }
        
    if(n == 1) {
        return 0;
    }
        
    vector<int>dp(n, -1);
    
    int ans = solve(height, n-1, dp);
    
    return ans;
}

// Input: 10, 20, 30, 10

// Output: 20
  
// Explanation:
// Geek jump from 1st to 2nd stair(|20-10| = 10 energy lost).
// Then a jump from the 2nd to the last stair(|10-20| = 10 energy lost).
// So, total energy lost is 20 which is the minimum.
