double myPow(double x, int n) {
    if (n == 0) {
        return 1;
    }

    if (n == 1) {
        return x;
    }

    if (n < 0) {
        x = 1 / x;
        // Special handling for n = INT_MIN, as -n would overflow
        if (n == INT_MIN) {
            return x * myPow(x, INT_MAX);
        } else {
            n = -n;
        }
    }

    double ans = myPow(x, n / 2);

    if (n % 2 == 0) {
        return ans * ans;
    } else {
        return x * ans * ans;
    }
}
