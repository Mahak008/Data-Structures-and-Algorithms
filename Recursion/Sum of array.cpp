int sum(int *arr, int size) {
    if(size == 0) {
        return 0;
    }
    if(size == 1) {
        return arr[0];
    }
    int ans = arr[0] + sum(arr+1, size-1);
    return ans;
}
