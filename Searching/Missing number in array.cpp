int missingNumber(vector<int>& array, int n) {
  int sum = 0, totalSum = 0;
  for(int i = 1; i <= n; i++) {
    sum += i;
  }
        
  for(int i = 0; i < n-1; i++) {
    totalSum += array[i];
  }
  return sum - totalSum;
}
