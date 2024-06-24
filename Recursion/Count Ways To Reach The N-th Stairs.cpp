int countDistinctWays(int n) {
    if(n < 0) {
        return 0;
    }
    if(n == 0) {
        return 1;
    }
    int ans = countDistinctWays(n-1) + countDistinctWays(n-2);
    return ans;
}

// Input: 2
// Output: 2
