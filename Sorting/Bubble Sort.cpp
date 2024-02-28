int arr[] = {13, 46, 24, 52, 20, 9};
int n = sizeof(arr)/sizeof(arr[0]);

for(int i = n-1; i >= 0; i--) {
  int sw = 0;
  for(int j = 0; j <= i-1; j++) {
    if(arr[j] > arr[j+1]) {
      swap(arr[j], arr[j+1]);
      sw = 1;
    }
  }
  if(sw == 0) {
    break;
  }
  cout << endl;
}

// Iteration in each step :-
// 13 24 46 52 20 9 
// 13 24 46 20 52 9 
// 13 24 46 20 9 52 

// 13 24 20 46 9 52 
// 13 24 20 9 46 52 

// 13 20 24 9 46 52 
// 13 20 9 24 46 52 

// 13 9 20 24 46 52 

// 9 13 20 24 46 52 

