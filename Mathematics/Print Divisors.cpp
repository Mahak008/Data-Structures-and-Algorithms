int n = 120;
int dig = int(sqrt(n));
vector <int> v;
for(int i = 1; i <= dig; i++) {
  if(n % i == 0) {
    v.push_back(i);

    if((n/i) != i) {
      v.push_back(n/i);
    }
  }
 }
sort(v.begin(), v.end());
for(auto it : v) {
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
