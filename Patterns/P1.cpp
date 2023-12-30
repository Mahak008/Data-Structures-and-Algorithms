int start = 0, n = 5;
for(int i = 0; i < n; i++) {
  if(i%2 == 0) {
    start = 1;
  }
  for (int j = 0; j <= i; j++) {
    cout << start;
    start = 1 - start;
  }
  cout << endl;
}

// Output -
// 1
// 01
// 101
// 0101
// 10101
