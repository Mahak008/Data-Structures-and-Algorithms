int n = 120;
int dig = int(sqrt(n));
set <int> s;
for(int i = 1; i <= dig; i++) {
  if(n % i == 0) {
    s.insert(i);

    if((n/i) != i) {
      s.insert(n/i);
    }
  }
 }

for(auto it : s) {
  cout << it << endl;
}

// Output -
// 1
// 2
// 3
// 4
// 5
// 6
// 8
// 10
// 12
// 15
// 20
// 24
// 30
// 40
// 60
// 120
