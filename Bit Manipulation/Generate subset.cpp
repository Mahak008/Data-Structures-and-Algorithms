// Power set algorithm

int arr[] = {3,2,4};
int n = sizeof(arr)/sizeof(arr[0]); // size of array

for(int num = 0; num < (1 << n); num++) { // 2^n-1  >> No. of subsets
  vector <int> ds; // empty vector
  
  for(int bit = 0; bit < n; bit++) { 
    if(num & (1 << bit)) {
      ds.push_back(arr[bit]);
    }
  }
  
  for(auto it : ds) {
    cout << it << " ";
  }
  cout << endl;
}

// Working
//     2 1 0 - (Power of 2 - 4, 2, 1)
// 0 | 0 0 0 - {}
// 1 | 0 0 1 - {3}
// 2 | 0 1 0 - {2}
// 3 | 0 1 1 - {3, 2}
// 4 | 1 0 0 - {4}
// 5 | 1 0 1 - {4, 3}
// 6 | 1 1 0 - {4, 2}
// 7 | 1 1 1 - {4, 2, 3}

// Output - 
// 3 
// 2 
// 3 2 
// 4 
// 3 4 
// 2 4 
// 3 2 4 
