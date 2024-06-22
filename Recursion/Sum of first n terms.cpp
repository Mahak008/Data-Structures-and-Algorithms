long long sumOfSeries(long long n) {
  long long ans = 0;
  if(n == 0) {
    return 0;
  }
  long long res = (n*n*n) + sumOfSeries(--n);
  return res;
}

// Input: n = 5
// Output: 225
// Explanation: 1^3 + 2^3 + 3^3 + 4^3 + 5^3 = 225
