int longestSuccessiveElements(vector<int>&a) {
    int n = a.size();
    int cnt = 0, max = 1, small = INT_MIN;
    sort(a.begin(), a.end());
    for(int i = 0; i < n; i++) {
        if((a[i]-1) == small) {
            cnt++;
            small = a[i];
        }
        else if(a[i] != small) {
            small = a[i];
            cnt = 1;
        }
        if(max < cnt) {
            max = cnt;
        }
    }
    return max;
}

// Input : 5, 8, 3, 2, 1, 4
// Output : 5
