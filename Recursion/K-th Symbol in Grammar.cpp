// Inductive Base Hypothesis

int kthGrammar(int n, int k) {
    int len = pow(2, n - 1);
    int mid = len / 2;
    int ans;

    if (n == 1 && k == 1) {
        return 0;
    }

    if (k <= mid) {
        ans = kthGrammar(n - 1, k);
    } else {
        ans = !(kthGrammar(n - 1, k - mid));
    }
    return ans;
}

// 0
// 0 1
// 0 1 1 0
// 0 1 1 0 1 0 0 1
// 0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
