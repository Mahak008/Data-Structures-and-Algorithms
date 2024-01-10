int n = 134, cnt = 0;

vector <int> v;
for(int i = 2; i*i <= n; i++) {
  if(n % i == 0) {
    cnt++;

    if((n/i) != i) {
      cnt++;
    }
  }
}

if(cnt == 2) {
    cout << "No";
} 
else {
    cout << "Yes";
}

// Output - 
// No
