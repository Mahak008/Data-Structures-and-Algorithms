int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int ans = n , low = 0, high = arr.size()-1;
	while(low <= high) {
		int mid = (high+low)/2;
		if(arr[mid] > x) {
			high = mid-1;
			ans = mid;
		}
		else {
			low = mid+1;
		}
	}
	return ans;
}

// The upper bound in a sorted array is the index of the first value that is greater than a given value. 
// Input: 5 7
// 1 4 7 8 10

// Output: 3   
