pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	// Write your code here.
	int low = 0, high = n-1;
	if (n == 0) {
        return {-1, -1};
    }
    if (x < a[low]) {
        return {-1, a[low]};
    } else if (x > a[high]) {
        return {a[high], -1};
    }

	while(low <= high) {
		int mid = (high + low)/2;
		if(a[mid] == x) {
                  return {a[mid], a[mid]};
                }
		else if(a[mid] > x) {
			high = mid-1;
		}
		else {
			low = mid + 1;
		}
	}
	return {a[high], a[low]};
}

Input: x=5, a=[3, 4, 7, 8, 8, 10]   
Output: 4
