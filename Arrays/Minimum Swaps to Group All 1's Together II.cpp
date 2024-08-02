// Leetcode - 2134

int minSwaps(vector<int>& nums) {
    int n = nums.size();
    int onesCount = 0;

    // Count total number of 1's in the array
    for (int num : nums) {
        if (num == 1) {
            onesCount++;
        }
    }

    if (onesCount == 0)
        return 0; // No 1's to group

    // Extend the array to handle circular nature
    vector<int> extended(nums.begin(), nums.end());
    extended.insert(extended.end(), nums.begin(), nums.end());

    // Find the minimum number of 0's in a window of size `onesCount`
    int minZeros = onesCount;
    int currentZeros = 0;

    // Initial window of size `onesCount`
    for (int i = 0; i < onesCount; ++i) {
        if (extended[i] == 0) {
            currentZeros++;
        }
    }

    minZeros = min(minZeros, currentZeros);

    // Slide the window
    for (int i = onesCount; i < extended.size(); ++i) {
        if (extended[i] == 0) {
            currentZeros++;
        }
        if (extended[i - onesCount] == 0) {
            currentZeros--;
        }
        minZeros = min(minZeros, currentZeros);
    }

    return minZeros;
}

// Input: nums = [0,1,0,1,1,0,0]
// Output: 1
// Explanation: Here are a few of the ways to group all the 1's together:
// [0,0,1,1,1,0,0] using 1 swap.
// [0,1,1,1,0,0,0] using 1 swap.
// [1,1,0,0,0,0,1] using 2 swaps (using the circular property of the array).
