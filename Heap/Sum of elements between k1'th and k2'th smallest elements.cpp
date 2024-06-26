long long sumBetweenTwoKth( long long A[], long long N, long long K1, long long K2){
  priority_queue<int, vector<int>, greater<int>> pq;
  
  for(int i = 0; i < N; i++) {
    pq.push(A[i]);
  }
        
  int m = 1;
  long long sum = 0;
        
  while(!pq.empty()) {
    if(m > K1 && m < K2) {
      sum += pq.top();
      pq.pop();
    }
    else{
      pq.pop();
    }
    m++;
  }
  return sum;
}

// Input: 20, 8, 22, 4, 12, 10, 14
// K1 = 3, K2 = 6
// Output: 26
  
// Explanation:
// 3rd smallest element is 10
// 6th smallest element is 20
// Element between 10 and 20 
// 12,14. Their sum = 26.
