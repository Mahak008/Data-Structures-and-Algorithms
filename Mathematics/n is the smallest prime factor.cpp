// n is the smallest prime factor of how many numbers in a range
int n = 50, r = 2;
vector <int> v(n+1, 1);
v[0] = v[1] = 0;

for(int i = 2; i*i <= n; i++) {
  if(v[i] == 1) {
    for(int j = i*i; j <= n; j+=i) {
      v[i]++;
      v[j] = 0;
    }
  }
}
cout << v[r];

// Output -
// 25
// 2 is the smallest prime factor of 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 42, 44, 46, 48, 50
