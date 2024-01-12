int n = 20;

vector <bool> v(n+1, true);

v[0] = v[1] = false;

for(int i = 2; i < n; i++) {
  if(v[i]) {
    for(int j = i*i; j < n; j+=i) { 
      v[j] = 0;
    }
  }
}

for (int p = 2; p < n; p++) {
  if (v[p]) {
    cout << p << " ";
  }
}

// Output - 
// 2 3 5 7 11 13 17 19 

// Time Complexity - (n * log(log(n))) 
