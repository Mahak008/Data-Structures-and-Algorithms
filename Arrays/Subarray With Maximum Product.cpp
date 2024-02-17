int subarrayWithMaxProduct(vector<int> &arr) {
  int prefix = INT_MIN, suffix = INT_MIN, p1 = 1, p2 = 1;
  for (int i = 0; i < arr.size(); i++) {
    p1 = p1 * arr[i];
    if (p1 == 0) {
      p1 = 1;
    }
    prefix = max(prefix, p1);
    p2 = p2 * arr[arr.size() - i - 1];
    if (p2 == 0) {
      p2 = 1;
    }
    suffix = max(suffix, p2);
  }
  if (suffix > prefix) {
    return suffix;
  }
  return prefix;
}

// Input : 1 -2 3 -4
// Output : 24
// Explanation: 
// The subarrays of ‘Arr’ are: 
// {{1}, {1, -2}, {1, -2, 3}, {1, -2, 3, -4}, {-2}, {-2, 3}, {-2, 3, -4}, {3}, {3, -4}, {-4}}.
// Among these subarrays, {1, -2, 3, -4} and {-2, 3, -4} have the maximum product, equal to 24.
// Hence, the answer is 24.
