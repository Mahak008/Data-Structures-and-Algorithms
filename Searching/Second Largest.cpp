// Function returns the second
// largest elements

int print2largest(int arr[], int n) {
  set <int> s;
  for(int i = 0; i < n; i++) {
    s.insert(arr[i]);
  }
	    
  auto it = s.begin();
  int l = s.size();
        
  for(int i = 0; i < l-2; i++) {
    it++;
  }
	
  int ans = *it;
	
  if(s.size() == 1) {
    return -1;
  }
  return ans;
}

//Second Method
// Function returns the second
// largest elements
int print2largest(int arr[], int n) {
  int large = 0, second = -1, ans = 0;

  // finding the largest element in the array
  for (int i = 1; i < n; i++) {
    if (arr[i] > arr[large]) {
      large = i;   
    }
  }

  // finding the largest element in the array excluding
  // the largest element calculated above
  for (int i = 0; i < n; i++) {
    if (arr[i] != arr[large]) {
      if (arr[i] > arr[second]) {
        second = i;
      }
    }
  }
        
  if(second == -1) {
    return -1;
  }
        
  ans = arr[second];
  return ans;
}

// Input: 
// N = 6
// Arr[] = {12, 35, 1, 10, 34, 1}

// Output: 34

// Explanation: The largest element of the array is 35 and the second largest element is 34.
