int n = 5, k = 2;
int n1 = n >> (k-1);
if(n1 & 1) {
  cout << '1';
}
else {
  cout << '0';
}

// Another method
int n = 5, k = 2;
int n1 = 1 << (k-1);
if(n1 & n) {
  cout << '1';
}
else {
  cout << '0';
}

// Output - 5(101)
// 0

