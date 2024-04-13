int lowerBound(vector<int> arr, int n, int x) {
	int ans = n , low = 0, high = arr.size()-1;
	while(low <= high) {
		int mid = (high+low)/2;
		if(arr[mid] >= x) {
			high = mid-1;
			ans = mid;
		}
		else {
			low = mid+1;
		}
	}
	return ans;
}

// For a sorted array 'arr', 'lower_bound' of a number 'x' is defined as the smallest index 'idx' such that the value 'arr[idx]' < x.
// Input: 1 2 2 3 3 5
// 2

// Output : 1
