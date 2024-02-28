int arr[] = {13, 46, 24, 52, 20, 9};

for(int i = 0; i <= n-2; i++) {
  int mini = i;
  for(int j = i; j <= n-1; j++) {
    if(arr[j] < arr[mini]) {
      mini = j;
    }
  }
  swap(arr[mini], arr[i]);
}

// Output after each iteration:
// 9 46 24 52 20 13 
// 9 13 24 52 20 46 
// 9 13 20 52 24 46 
// 9 13 20 24 52 46 
// 9 13 20 24 46 52 
