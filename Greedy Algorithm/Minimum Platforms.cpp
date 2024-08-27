int findPlatform(int arr[], int dep[], int n) {
	vector<pair<int,int>>temp;
	for(int i = 0; i < n; i++) {
	    temp.push_back({arr[i], 0});
	}
    	
	for(int i = 0; i < n; i++) {
	    temp.push_back({dep[i], 1});
	}
    	
	sort(temp.begin(), temp.end());
	int maxCnt = INT_MIN, cnt = 0;
    	
	for(int i = 0; i < temp.size(); i++) {
	    if(temp[i].second == 0) {
	        cnt++;
	    } else if(temp[i].second == 1) {
	        cnt--;
	    }
    	    
	    maxCnt = max(maxCnt, cnt);
	}
    	
	return maxCnt;
}

// Input: n = 6, arr[] = {0900, 0940, 0950, 1100, 1500, 1800}, 
            // dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
// Output: 3
