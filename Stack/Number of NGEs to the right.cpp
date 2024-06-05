vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
  vector <int> v;
  while(queries > 0) {
    int cnt = 0;
    for(int j = indices[queries-1] + 1; j < n; j++) {
      if(arr[j] > arr[indices[queries-1]]) {
        cnt++;
      }
    }
    v.push_back(cnt);
    --queries;
  }
  reverse(v.begin(), v.end());
  return v;
}

// Another Way
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices){
  vector <int> v;
  for(int i = 0; i < indices.size(); i++) {
    int cnt = 0;
    for(int j = indices[i] + 1; j < arr.size(); j++) {
      if(arr[j] > arr[indices[i]]) {
        cnt++;
      }
    }
    v.push_back(cnt);
  }
  return v;
}

// Input:  arr     = [3, 4, 2, 7, 5, 8, 10, 6]
//         queries = 2
//         indices = [0, 5]
// Output:  6, 1
