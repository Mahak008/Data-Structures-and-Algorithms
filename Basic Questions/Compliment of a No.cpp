int n = 100, ans = 0, i = 0, j = 0, bit;
while(n > 0) {
  bit =  n & 1;
  if(bit == 1) {
    ans = 0 * pow(10, i) + ans;
  }
  else {
    ans = 1 * pow(10, i) + ans;
  }
  n = n >> 1;
  i++;
}
    
int rem, res = 0;
while(ans > 0) {
  rem = ans % 10;
  res = rem * pow(2,j) + res;
  j++;
  ans /= 10;
}
cout << res;

// Input - 100 - 1100100
// Output - 27 - 11011  
