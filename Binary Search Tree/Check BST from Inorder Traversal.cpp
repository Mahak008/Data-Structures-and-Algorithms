bool isBSTTraversal(vector<int>& arr) {
  for(int i = 1; i < arr.size(); i++) {
    if(arr[i] <= arr[i-1]) {
      return false;
    }
  }
  return true;
}

// Input: arr[] = [8, 14, 45, 64, 100]
// Output: True
