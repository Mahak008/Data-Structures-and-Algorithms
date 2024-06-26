long long connectRopes(int *arr, int n) {
  long long ans = 0;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n; i++) {
    pq.push(arr[i]);
  }

  while (pq.size() > 1) {
    int num1 = pq.top();
    pq.pop();

    if (!pq.empty()) {
      int num2 = pq.top();
      pq.pop();
      int sum = num1 + num2;
      ans += sum;
      pq.push(sum);
    } else {
      ans += num1; // If only one rope left
    }
  }
  return ans;
}

// Input: 4 3 2 6
// Output: 29

// Explanation:
// 1) If we first connect ropes of lengths 2 and 3, we will left with three ropes of lengths 4, 6 and 5.

// 2) Now then, if we connect ropes of lengths 4 and 5, we will left with two ropes of lengths 6 and 9.

// 3) Finally, we connect the remaining two ropes and all ropes are now connected.

// Total cost for connecting all ropes in this way is 5 + 9 + 15 = 29  which is the optimized cost.
