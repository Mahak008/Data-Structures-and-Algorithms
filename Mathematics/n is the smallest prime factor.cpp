// n is the smallest prime factor of how many numbers in a range
int n = 20, r = 3;
vector <int> v(n+1, 1);
v[0] = v[1] = 0;

for(int i = 2; i*i <= n; i++) {
  if(v[i] == 1) {
    for(int j = i*i; j <= n; j+=i) {
      if(v[j] != 0) {
        v[i]++;
        v[j] = 0;
      }
    }
  }
}
cout << v[r];


// Output -
// 3
// 2 is the smallest prime factor of 3 6, 15
