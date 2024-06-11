long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
  deque<int> maxi(k);
  deque<int> mini(k);

  // Addition of first k size window
  for (int i = 0; i < k; i++) {
    while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
      maxi.pop_back();
    }

    while (!mini.empty() && arr[mini.back()] >= arr[i]) {
      mini.pop_back();
    }
    maxi.push_back(i);
    mini.push_back(i);
  }

  long long ans = 0;

  for (int i = k; i < n; i++) {
    ans += arr[maxi.front()] + arr[mini.front()];

    // removal
    while (!maxi.empty() && i - maxi.front() >= k) {
      maxi.pop_front();
    }

    while (!mini.empty() && i - mini.front() >= k) {
      mini.pop_front();
    }

    // addition
    while (!maxi.empty() && arr[maxi.back()] <= arr[i]) {
      maxi.pop_back();
    }

    while (!mini.empty() && arr[mini.back()] >= arr[i]) {
      mini.pop_back();
    }
    maxi.push_back(i);
    mini.push_back(i);
  }

  // make sure to consider last window
  ans += arr[maxi.front()] + arr[mini.front()];
  return ans;
}

// Input: 1 2 3 4 5
// Maxi - 3 4 5
// Mini - 1 2 3
// Output : 3 + 1 + 4 + 2 + 5 + 3 = 18
