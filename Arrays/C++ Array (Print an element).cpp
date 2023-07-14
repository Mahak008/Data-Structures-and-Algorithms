// function to return an element
// present at index key in the array

int findElementAtIndex(int a[], int n, int key) {
  int ans = 0;
  for(int i = 0; i <= key; i++) {
    ans = a[i];
  }
  return ans;
}