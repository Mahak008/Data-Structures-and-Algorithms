// Given an array of integers and a position ‘m’. You have to reverse the array after the mth position.

vector<int> rev(vector<int>&arr, int l, int r) {
 if(l >= r) {
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
