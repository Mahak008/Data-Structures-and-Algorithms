int getKthLargest(vector<int> &arr, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  int x;

  for (int i = 0; i < arr.size(); i++) {
    int sum = 0;

    for (int j = i; j < arr.size(); j++) {
      sum += arr[j];

      if (pq.size() < k) {
        pq.push(sum);
      } else {
        if (sum > pq.top()) {
          pq.pop();
          pq.push(sum);
        }
      }
    }
  }

  return pq.top();
}

// Input: k = 3, arr = 3 -2 5
// Output: 3

// Explanation: 
// Sum of [0, 0] = 3
// Sum of [0, 1] = 1
// Sum of [0, 2] = 6
// Sum of [1, 1] = -2
// Sum of [1, 2] = 3
// Sum of [2, 2] = 5
// All sum of subarrays are {6, 5, 3, 3, 1, -2} where the third largest element is 3.
