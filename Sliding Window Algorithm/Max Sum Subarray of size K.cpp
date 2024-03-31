long maximumSumSubarray(int K, vector<int> &Arr , int N){
  long Max = 0;
  long sum = 0;
  int i = 0, j ;

  for (j = 0; j < K; ++j) {
    sum += Arr[j];
  }
  Max = sum;
    
  while (j < N) {
    sum += Arr[j] - Arr[i];
    Max = max(Max, sum);
    ++i;
    ++j;
  }
  return Max;
}

// Input:
// N = 4, K = 2
// Arr = [100, 200, 300, 400]
// Output:
// 700
