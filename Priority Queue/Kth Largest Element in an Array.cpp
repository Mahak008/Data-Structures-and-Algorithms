int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int> pq;
    int x;
    for (int i : nums) {
        pq.push(i);
    }
    while (k--) {
        x = pq.top();
        pq.pop();
    }
    return x;
}

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
