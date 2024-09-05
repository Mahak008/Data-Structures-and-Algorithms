// Leetcode - 2028

vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int sum = 0;
    for (int& i : rolls) {
        sum += i;
    }

    int m = rolls.size();
    int len = n + m;

    int mSum = mean * len - sum;

    if (mSum < n || mSum > 6 * n) {
        return {};
    }

    vector<int> ans(n, 1);
    mSum -= n; // Start by assigning 1 to each roll

    for (int i = 0; i < n; ++i) {
        int add = min(5, mSum); // Each roll can go up to 6, so add at most 5
        ans[i] += add;
        mSum -= add;
        if (mSum <= 0)
            break;
    }

    return ans;
}

// Input: rolls = [3,2,4,3], mean = 4, n = 2
// Output: [6,6]
// Explanation: The mean of all n + m rolls is (3 + 2 + 4 + 3 + 6 + 6) / 6 = 4.
