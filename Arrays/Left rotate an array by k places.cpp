vector<int> rotateArray(vector<int>arr, int k) {
    int n = arr.size();
    k = k % n;
    vector <int> v;
    int temp[k];
    for(int i = 0; i < k; i++) {
        temp[i] = arr[i];
    }
    for(int i = k; i < arr.size(); i++) {
        arr[i-k] = arr[i];
    }
    for(int i = (n-k); i < n; i++) {
        arr[i] = temp[i-(n-k)];
    }
    for(int i = 0; i < n; i++) {
        v.push_back(arr[i]);
    }
    return v;
}

// Input :
// 7 5 2 11 2 43 1 1
// 2
// Output :
// 2 11 2 43 1 1 7 5
