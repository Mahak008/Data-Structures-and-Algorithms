int bS(int *arr, int low, int high, int x) {
    if(low > high) {
        return -1;
    }
    int mid = (low + high)/2;
    if(x == arr[mid]) {
        return mid;
    }
    else if(x > arr[mid]) {
        return bS(arr,mid+1, high, x);
    }
    return bS(arr, low, mid-1, x);
}
