int nCr(int n, int r) {
  long long res = 1;
  for(int i = 0; i < n; i++){
    res *= (n-i);
    res /= (i+1);
  }
  return res;
}

// Find the value of particular place in Pascal's triangle
