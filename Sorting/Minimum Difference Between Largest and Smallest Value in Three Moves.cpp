int minDifference(vector<int>& nums) {
    int n = nums.size(), mini = INT_MAX;

    if (nums.size() <= 4) {
        return 0;
    }

    sort(nums.begin(), nums.end());

    for (int i = 1; i <= 4; i++) {
        mini = min(mini, abs(nums[n - i] - nums[4 - i]));
    }

    return mini;
}

// Time - O(N log N)
// Input - 1, 5, 6, 14, 15, 16, 18, 19
// Output - 5
