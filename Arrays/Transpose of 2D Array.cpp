vector<vector<int>> transpose(int a[][M], int n) {
  vector<vector<int>> v;
  for(int i = 0; i < n; i++) {
    vector <int> v1;
        
    for(int j = 0; j < n; j++) {
      v1.push_back(a[j][i]);
    }
    v.push_back(v1);
  }
  return v;
}

// Input : arr[] = {{1,2,3}, {4,5,6}, 
//                   {7,8,9}} and N = 3
// Output : 1 4 7 2 5 8 3 6 9
// Explanation:1 2 3       1 4 7
//             4 5 6 ----> 2 5 8
//             7 8 9       3 6 9
// Transpose of array.
