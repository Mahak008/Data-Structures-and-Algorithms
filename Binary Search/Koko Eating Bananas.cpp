int findMax(vector<int> &v) {
  int maxi = INT_MIN;
  int n = v.size();
  for (int i = 0; i < n; i++) {
    maxi = max(maxi, v[i]);
  }
  return maxi;
}

long long totalHrs(vector<int> &v, int hourly) {
  long long totalH = 0;
  int n = v.size();
  for (int i = 0; i < n; i++) {
    totalH += ceil((double)(v[i]) / (double)(hourly));
  }
  return totalH;
}
int minimumRateToEatBananas(vector<int> piles, int h) {
  int low = 1, high = findMax(piles);
  while (low <= high) {
    int mid = (low + high) / 2;
    long long hrs = totalHrs(piles, mid);
    if (hrs <= h) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
