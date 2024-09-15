// Leetcode - 2419

int longestSubarray(vector<int>& nums) {
    int n = nums.size();
    int m = max_element(nums.begin(), nums.end()) - nums.begin();

    int maxLen = 0, x = nums[m];

    for (int i = m; i < n; ++i) {
        int len = 0;

        while (i < n && nums[i] == x) {
            i++;
            len++;
        }

        maxLen = max(maxLen, len);
    }

    return maxLen;
}

// Input: nums = [1,2,3,3,2,2]
// Output: 2
// Explanation:
// The maximum possible bitwise AND of a subarray is 3.
// The longest subarray with that value is [3,3], so we return 2.
