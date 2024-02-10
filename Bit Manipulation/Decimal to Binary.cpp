int n = 20, ans = 0, i = 0, bit;
while(n > 0) {
  bit =  n & 1;
  ans = bit * pow(10, i) + ans;
  n = n >> 1;
  i++;
}
cout << ans;

// Output - 10100


// Binary to Decimal
int n = 110, ans = 0, i = 0, bit;
while(n > 0) {
  bit =  n % 10;
  if(bit == 1) {
    ans = bit * pow(2,i) + ans;
  }
  n /= 10;
  i++;
}
cout << ans;

// Output - 20 
