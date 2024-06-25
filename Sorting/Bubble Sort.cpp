// Push largest element at the end
int arr[] = {13, 46, 24, 52, 20, 9};

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
}

// Recursion
void bubbleSort(int arr[], int n) {
  if(n == 0 || n == 1) {
    return;
  }
  
  for(int i = 0; i < n-1; i++) {
    if(arr[i] > arr[i+1]) {
      swap(arr[i], arr[i+1]);
    }
  }
        
  bubbleSort(arr, n-1);
}

// Output after each Iteration:
// 13 24 46 52 20 9 
// 13 24 46 20 52 9 
// 13 24 46 20 9 52 

// 13 24 20 46 9 52 
// 13 24 20 9 46 52 

// 13 20 24 9 46 52 
// 13 20 9 24 46 52 

// 13 9 20 24 46 52 

// 9 13 20 24 46 52 

