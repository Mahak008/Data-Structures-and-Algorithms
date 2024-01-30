int n1 = 21, n2 = 100;
int n = min(n1, n2);
for(int i = n; i >= 1; i--) {
    if(n1 % i == 0 && n2 % i == 0) {
        cout << i;
        break;
    }
}

// Optimised Approach

if(n == 0 || n == m) {
        return m;
}

if(m == 0) {
  return n;
}

if (n > m) {
  if (n % m == 0)
    return m;
  return calcGCD(n - m, m);
}

if (m % n == 0)
  return n;
return calcGCD(n, m - n);

// Output - 
// 1
