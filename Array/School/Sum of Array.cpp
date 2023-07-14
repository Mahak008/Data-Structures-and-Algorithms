// function to return sum of elements
// in an array of size n
int sum(int arr[], int n) {
  int ans = 0;
  for(int i = 0; i < n; i++) {
	ans += arr[i];
  }
  return ans;
}