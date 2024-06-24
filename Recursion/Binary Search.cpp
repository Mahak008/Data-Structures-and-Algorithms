bool b_search(int *arr, start, end, k) {
  if(start > end) {
    return false;
  }

  int mid = (start + end)/2;
  
  if(arr[mid] == k) {
    return true;
  }
  else if(arr[mid] < k) {
    return b_search(arr, start, mid-1, k);
  }
  else {
    return b_search(arr, mid+1, end, k);
  }
  return false;
}
