// Leetcode - 703

priority_queue<int, vector<int>, greater<int>> pq;
int K;

KthLargest(int k, vector<int>& nums) {
    K = k;
    for (auto i : nums) {
        pq.push(i);
    }
    while (pq.size() > K) {
        pq.pop();
    }
}

int add(int val) {
    pq.push(val);

    if (pq.size() > K) {
        pq.pop();
    }

    return pq.top();
}

// Input
// ["KthLargest", "add", "add", "add", "add", "add"]
// [[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
// Output
// [null, 4, 5, 5, 8, 8]
