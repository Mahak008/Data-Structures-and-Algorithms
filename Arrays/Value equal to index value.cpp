// function to return an element
// whose value is equal to its index value in the array

vector<int> valueEqualToIndex(int arr[], int n) {
  vector<int> v;
  for(int i = 0; i < n; i++) {
    if(arr[i] == i+1) {
      v.push_back(arr[i]);
    }
  }
  return v;
}
