void printNos(int N) {
  if(N == 0) {
    return;
  }
  printNos(N-1);
  cout << N << " ";
}

// Input: n = 5
// Output: 1 2 3 4 5
