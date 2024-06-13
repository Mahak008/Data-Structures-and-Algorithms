// If cnt is strictly greater than mid. According to the Pigeonhole Principle, repeated elements are in the interval [left,mid];
// Otherwise, the repeated element is in the interval [mid+1,right].

int findDuplicate(vector<int>& nums) {
    int len = nums.size();
    int low = 1;
    int high = len - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int cnt = 0;
        for (int i = 0; i < len; i++) {
            if (nums[i] <= mid) {
                cnt++;
            }
        }

        if (cnt <= mid) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}

// Input: nums = [1,3,4,2,2]
// Output: 2
