int maxPoints(vector<int> &cardPoints, int k) {
  int n = cardPoints.size();
  int lSum = 0, rSum = 0, l = 0, r = n - 1, sum = 0, maxSum = 0;
  while (l < k) {
    sum = sum + cardPoints[l];
    ++l;
  }
  maxSum = sum;
  while (l > 0) {
    sum = sum - cardPoints[l - 1] + cardPoints[r];
    maxSum = max(sum, maxSum);
    --l;
    --r;
  }
  return maxSum;
}
