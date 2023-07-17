vector <int> v, ans;
for(int i = 0; i < n; i++) {
  if(a[i] == key) {
    v.push_back(i);
  }
}
if(v.empty()) {
  v.push_back(-1);
}
ans.push_back(v.front());
ans.push_back(v.back());
return ans;

// Input:
// N = 6
// arr[] = { 1, 2, 3, 4, 5, 5 }
// Key = 5
// Output:  4 5
// Explanation:
// 5 appears first time at index 4 and
// appears last time at index 5.
// (0 based indexing)
