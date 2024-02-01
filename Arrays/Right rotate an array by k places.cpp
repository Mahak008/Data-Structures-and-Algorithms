void rotate(vector<int>& arr, int k) {
  int n = arr.size();
  k = k % n;
  reverse(arr.begin(), arr.begin() + n - k);
  reverse(arr.begin() + n - k, arr.begin() + n);
  reverse(arr.begin(), arr.begin() + n);
}

// Input: nums = [1,2,3,4,5,6,7], k = 3
// Output: [5,6,7,1,2,3,4]
