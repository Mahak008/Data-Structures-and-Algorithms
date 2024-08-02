int lcs(string &str1,string &str2,int i,int j,vector<vector<int>>&dp){
    if(i==0||j==0){
        return 0;
    }

    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(str1[i-1]==str2[j-1]){
        return dp[i][j]=1 + lcs(str1,str2,i-1,j-1,dp);
    } else{
        return dp[i][j]=max(lcs(str1,str2,i,j-1,dp),lcs(str1,str2,i-1,j,dp));
    }
}
    
int countMin(string str){
    string str1 = str;
    int n = str.size();
    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    
    reverse(str1.begin(),str1.end());
    return str.size()-lcs(str,str1, n, n,dp);
}

// Input: str = "abcd"
// Output: 3
// Explanation: Inserted character marked with bold characters in dcbabcd, here we need minimum three characters to make it palindrome.
