long long sumOfSeries(long long n) {
  long long ans = 0;
  if(n == 0) {
    return 0;
  }
  ans += (n*n*n);
  long long res = sumOfSeries(--n);
  return ans + res;
}

// Input: n = 5
// Output: 225
// Explanation: 1^3 + 2^3 + 3^3 + 4^3 + 5^3 = 225
