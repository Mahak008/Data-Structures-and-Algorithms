// Leetcode - 55

bool canJump(vector<int>& nums) {
    int maxInd = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxInd) {
            return false;
        }
        maxInd = max(maxInd, i + nums[i]);
    }

    return true;
}

// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
