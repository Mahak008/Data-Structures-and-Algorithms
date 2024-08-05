// Leetcode - 1508

const int mod = 1e9 + 7;
int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> temp;

    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = i; j < n; ++j) {
            sum += nums[j];
            temp.push_back(sum);
        }
    }

    sort(temp.begin(), temp.end());

    int ans = 0;
    for (int i = left - 1; i < right; i++) {
        ans += temp[i];
        ans %= mod;
    }

    return ans;
}

// Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
// Output: 13 
// Explanation: All subarray sums are 1, 3, 6, 10, 2, 5, 9, 3, 7, 4. After sorting them in non-decreasing order we have the new array [1, 2, 3, 3, 4, 5, 6, 7, 9, 10]. The sum of the numbers from index le = 1 to ri = 5 is 1 + 2 + 3 + 3 + 4 = 13. 
