int n = 10;
int dig = log2(n) + 1;
int mask = (1 << dig) - 1;
int res  = (mask ^ n);
cout res;

// Output - 5
