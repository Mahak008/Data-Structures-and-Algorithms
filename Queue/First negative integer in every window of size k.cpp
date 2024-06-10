vector<long long> printFirstNegativeInteger(long long int A[],long long int N, long long int K) {
  queue<long long> q;
  vector<long long> ans;

  // Process first window of size k
  for(int i = 0; i < K; i++) {
    if(A[i] < 0) {
      q.push(i);
    }
  }

  // Store ans of first k size window
  if(q.size() > 0) {
    ans.push_back(A[q.front()]);
  } 
  else {
    ans.push_back(0);
  }

  // Process Remaining Elements
  for(int i = K; i < N; i++) {
    // Removal
    if(!q.empty() && i - q.front() >= K) {
      q.pop();
    }

    // Addition
    if(A[i] < 0) {
      q.push(i);
    }

    // Push ans to vector
    if(q.size() > 0) {
      ans.push_back(A[q.front()]);
    } 
    else {
      ans.push_back(0);
    }
  }
  return ans;                                         
}

// Input : -8, 2, 3, -6, 10 K = 2
// Output : -8 0 -6 -6
