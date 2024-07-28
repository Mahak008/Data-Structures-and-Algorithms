void buildTree(vector<int>& segTree, int arr[], int low, int high, int pos) {
    if (low == high) {
        segTree[pos] = arr[low];
        return;
    }
    
    int mid = (low + high) / 2;
    
    buildTree(segTree, arr, low, mid, 2 * pos + 1);
    buildTree(segTree, arr, mid + 1, high, 2 * pos + 2);
    
    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int query(vector<int>& segTree, int start, int end, int low, int high, int pos) {
    if(low > end || high < start) {
        return 0;
    }    
    
    if(low >= start && high <= end) {
        return segTree[pos];
    }
    
    int mid = (low + high) / 2;
    
    return query(segTree, start, end, low, mid, 2 * pos + 1) + query(segTree, start, end, mid + 1, high, 2 * pos + 2);
}

vector<int> querySum(int n, int arr[], int q, int queries[]) {
    int x = ceil(log2(n));
    int size = 2 * (int)(pow(2, x)) - 1;
    
    vector<int>segTree(size, 0);
    buildTree(segTree, arr, 0, n-1, 0);
    
    vector<int> res;
    for(int i = 0; i < 2*q; i+=2) {
        int start = queries[i] - 1;
        int end = queries[i+1] - 1;
        
        res.push_back(query(segTree, start, end, 0, n-1, 0));
    }
    
    return res;
}

// Input: n = 4
// arr = {1, 2, 3, 4}
// q = 2
// queries = {1, 4, 2, 3}

// Output: 10 5

// Explaination: 
// In the first query we need sum from 1 to 4 which is 1+2+3+4 = 10. 
// In the second query we need sum from 2 to 3 which is 2 + 3 = 5.
