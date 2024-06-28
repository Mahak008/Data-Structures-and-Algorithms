void generateSubsets(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans) {

    // Base case: when index reaches the size of nums, add the current
    // subset to the result
    if (index >= nums.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude the current element and move to the next
    generateSubsets(nums, output, index + 1, ans);

    // Recursive case 2: Include the current element and move to the next
    int ele = nums[index];
    output.push_back(ele);
    generateSubsets(nums, output, index + 1, ans);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    generateSubsets(nums, output, index, ans);
    return ans;
}

// Input: nums = 1, 2, 3
// Output: [], [1], [2], [1,2], [3], [1,3], [2,3], [1,2,3]
