int lower_bound(const vector<int>& arr, int size, int x) {
        int low = 0, high = size - 1, ans = size;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int cnt_max = 0, index = -1;
	    for(int i = 0; i < n; i++) {
	        int cnt = m - lower_bound(arr[i], m, 1);
	        if(cnt_max < cnt) {
	            cnt_max = cnt;
	            index = i;
	        }
	    }
	    return index;
	}
