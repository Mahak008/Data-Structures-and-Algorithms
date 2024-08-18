// Leetcode - 264

int nthUglyNumber(int n) {
    vector<int> dp(n);
    dp[0] = 1;

    int p1 = 0;
    int p2 = 0;
    int p3 = 0;

    for (int i = 1; i < n; i++) {

        int twoMul = dp[p1] * 2;
        int threeMul = dp[p2] * 3;
        int fiveMul = dp[p3] * 5;

        dp[i] = min(twoMul, min(threeMul, fiveMul));

        if (dp[i] == twoMul)
            p1++;
        if (dp[i] == threeMul)
            p2++;
        if (dp[i] == fiveMul)
            p3++;
    }

    return dp[n - 1];
}

// Input: n = 10
// Output: 12
// Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
