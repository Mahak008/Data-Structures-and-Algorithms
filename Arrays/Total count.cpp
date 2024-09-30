int totalCount(int k, vector<int>& arr) {
    int cnt = 0;
    int q = 0;
    int n = arr.size();
    
    for(int i = 0; i < n; i++) {
        if(arr[i] <= k) {
            cnt++;
        } else if(arr[i] % k > 0) {
            q = arr[i] / k;
            cnt += (q + 1);
        } else {
            q = arr[i] / k;
            cnt += q;
        }
    }
    
    return cnt;
}

// Input: k = 4, arr[] = [10, 2, 3, 4, 7]
// Output: 8
// Explanation: Each number can be expressed as sum of different numbers less than or equal to k as 10 (4 + 4 + 2), 2 (2), 3 (3), 4 (4) and 7 (4 + 3).So, the sum of count of each element is (3 + 1 + 1 + 1 + 2) = 8.
