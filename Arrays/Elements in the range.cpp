bool check_elements(int arr[], int n, int A, int B) {
	sort(arr, arr+n);
	for(int i = 0; i < n; i++) {
		if(arr[i] == A && arr[i] <= B) {
		  A++;
		}
	}
	if(A <= B) {
		return 1;
	}
	return 0;
}
