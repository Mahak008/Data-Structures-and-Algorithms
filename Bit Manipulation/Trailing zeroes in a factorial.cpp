int n = 30, sum = 0;
for(int i = 5; i <= n; i *= 5) {
   sum += n/i;
}
cout << sum;

// Output -
// 7
