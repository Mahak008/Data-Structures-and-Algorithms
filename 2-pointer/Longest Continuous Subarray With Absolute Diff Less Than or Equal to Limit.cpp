int mini(vector<int>& nums, int l, int r) {
    int x = INT_MAX;
    for (int i = l; i <= r; i++) {
        if (x > nums[i]) {
            x = nums[i];
        }
    }
    return x;
}

int maxi(vector<int>& nums, int l, int r) {
    int x = INT_MIN;
    for (int i = l; i <= r; i++) {
        if (x < nums[i]) {
            x = nums[i];
        }
    }
    return x;
}

int longestSubarray(vector<int>& nums, int limit) {
    int l = 0, r = 0, ans = 0;
    int n = nums.size();
    while (r < n) {
        int minii = mini(nums, l, r);
        int maxii = maxi(nums, l, r);
        int diff = maxii - minii;

        if (diff <= limit) {
            ans = max(ans, r - l + 1);
            r++;
        } else {
            l++;
        }
    }
    return ans;
}

// Input: nums = [10,1,2,4,7,2], limit = 5
// Output: 4 
// Explanation: The subarray [2,4,7,2] is the longest since the maximum absolute diff is |2-7| = 5 <= 5.
