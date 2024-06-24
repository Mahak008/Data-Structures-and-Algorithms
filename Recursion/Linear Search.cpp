bool linear(int *arr, int size, int k) {
    bool ans;
    if(size == 0) {
        return false;
    }
    if(arr[0] == k) {
        return true;
    }
    else {
        ans = linear(arr+1, size-1, k);
    }
    return ans;
}
