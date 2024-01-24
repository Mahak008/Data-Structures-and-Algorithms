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
