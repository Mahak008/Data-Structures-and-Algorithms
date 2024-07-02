const int MOD = 1e9 + 7;

int myPow(int x, long long n, int mod) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    long long ans = myPow(x, n / 2, mod);

    if (n % 2 == 0) {
        return (ans * ans) % mod;
    } else {
        return (x * ans * ans) % mod;
    }
}

int countGoodNumbers(long long n) {
    if (n == 1) {
        return 5;
    }
    long long a, b;
    if (n % 2 == 0) {
        a = myPow(5, n / 2, MOD);
        b = myPow(4, n / 2, MOD);
    } else {
        a = myPow(5, n / 2 + 1, MOD);
        b = myPow(4, n / 2, MOD);
    }
    return (a * b) % MOD;
}

// Input: n = 1
// Output: 5
// Explanation: The good numbers of length 1 are "0", "2", "4", "6", "8".
// Prime - 2, 3, 5, 7
// Even - 0, 2, 4, 6, 8
