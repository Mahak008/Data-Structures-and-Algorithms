vector<int> rev(vector<int>&arr, int l, int r) {
 while(l >= r) {
     return arr;
 }   
 
 swap(arr[l], arr[r]);
 return rev(arr, l+1, r-1);
}

void reverseArray(vector<int> &arr , int m) {
    int l = m+1;
    int r = arr.size()-1;
    rev(arr, l, r);
}
