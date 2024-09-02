// Leetcode - 1894

int chalkReplacer(vector<int>& chalk, int k) {
    int n = chalk.size();
    vector<long long> preSum(n);
    preSum[0] = chalk[0];

    for (int i = 1; i < n; i++) {
        preSum[i] = preSum[i - 1] + chalk[i];
    }

    long long x = k % preSum[n - 1];

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        if (preSum[mid] <= x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

// Input: chalk = [3,4,1,2], k = 25
// Output: 1
