int n = 50;
vector <int> v;
for(int i = 0; i <= n; i++) {
  v.push_back(i);
}

for(int i = 2; i*i <= n; i++) {
  if(v[i] == i) {
    for(int j = i*i; j <= n; j+=i) {
      if(v[j] == j) {
        v[j] = i;
      }
    }
  }
}
    
while(n != 1) {
  cout << v[n] << " ";
  n /= v[n];
}

// Output - 
// 2 5 5 
