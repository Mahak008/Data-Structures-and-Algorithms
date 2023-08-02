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

// Input: N = 7, A = 2, B = 5
// arr[] =  {1, 4, 5, 2, 7, 8, 3}

// Output: Yes
// Explanation: It has elements between range 2-5 i.e 2,3,4,5
