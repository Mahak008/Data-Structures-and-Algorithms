long long fact(long long n) {
  if(n == 1 || n == 0) {
    return 1;
  }
        
  long long ans = n * fact(n-1);
  return ans;
}
    
vector<long long> factorialNumbers(long long n) {
  vector<long long> v;
  
  for(int i = 1; i <= n; i++) {
    long long x = fact(i);
            
    if(x > n) {
      break;
    }
            
    v.push_back(x);
  }   
  return v;
}

// Input: n = 6
// Output: 1 2 6
// Explanation: The first three factorial numbers are less than equal to n but the fourth factorial number 24 is greater than n. So we print only first three factorial numbers.
