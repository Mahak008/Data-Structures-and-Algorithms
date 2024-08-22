// Leetcode - 476

if(n == 0) {
  return 1;
}

int n = 10;
int dig = log2(n) + 1;
int mask = (1 << dig) - 1;
int res  = (mask ^ n);
cout res;

// Alternative Approach

int n = 10, mask = 0;
int m = n;
while(m > 0) {
    mask = (mask << 1) | 1;
     m = m >> 1;
}
int res  = (mask ^ n);
cout << mask << endl << res;

// Output - 5
