// Leetcode - 719

int smallestDistancePair(vector<int>& nums, int k) {
    int max_el = *max_element(nums.begin(), nums.end());
    vector<int> ans(max_el + 1, 0);

    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            int x = abs(nums[i] - nums[j]);
            ans[x]++;
        }
    }

    for (int i = 0; i < max_el + 1; i++) {
        k -= ans[i];
        if (k <= 0) {
            return i;
        }
    }

    return -1;
}

// Input: nums = [1,3,1], k = 1
// Output: 0
// Explanation: Here are all the pairs:
// (1,3) -> 2
// (1,1) -> 0
// (3,1) -> 2
// Then the 1st smallest distance pair is (1,1), and its distance is 0.
