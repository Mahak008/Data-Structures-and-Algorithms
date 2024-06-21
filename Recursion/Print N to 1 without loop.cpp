void printNos(int N) {
  if(N == 0) {
    return;
  }
  
  cout << N << " ";
  printNos(N-1);
}

// Input: N = 5
// Output: 5 4 3 2 1
