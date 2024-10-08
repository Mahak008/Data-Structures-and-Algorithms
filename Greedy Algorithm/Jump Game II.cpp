// Leetcode - 45

int solve(vector<int>& nums, int idx) {
    int n = nums.size();

    if (n <= 1) {
        return 0;
    }

    if (idx >= n - 1) {
        return 0;
    }

    int mini = INT_MAX;

    for (int i = 1; i <= nums[idx]; i++) {
        if (idx + i < n) { // Check to ensure we are within bounds
            int jumps = solve(nums, idx + i);
            if (jumps != INT_MAX) {
                mini = min(mini, jumps + 1);
            }
        }
    }

    return mini;
}

int jump(vector<int>& nums) { 
  return solve(nums, 0); 
}

// Time Limit Exceeded

// Approach - check in range
int jump(vector<int>& nums) {
    int n = nums.size();
    int j = 0, l = 0, r = 0;
    while (r < n - 1) {
        int farthest = 0;
        for (int i = l; i <= r; i++) {
            farthest = max(farthest, i + nums[i]);
        }
        l = r + 1;
        r = farthest;
        j++;
    }
    return j;
}

// Time - O(N)
// Space - O(1)

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
