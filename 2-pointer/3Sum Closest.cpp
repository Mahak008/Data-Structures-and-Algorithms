int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int ans = nums[0] + nums[1] + nums[2];

    for (int i = 0; i < nums.size() - 2; i++) {

        int j = i + 1;
        int k = nums.size() - 1;

        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];

            if (abs(sum - target) < abs(ans - target)) {
                ans = sum;
            }

            if (sum == target) {
                return sum;
            }

            else if (sum < target) {
                j++;
            }

            else {
                k--;
            }
        }
    }
    return ans;
}

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
