int b_search(vector<int> &arr, int start, int end, int k) {
  if(start > end) {
    return -1;
  }

  int mid = (start + end)/2;
  
  if(arr[mid] == k) {
    return mid;
  }
  else if(arr[mid] > k) {
    return b_search(arr, start, mid-1, k);
  }
  else {
    return b_search(arr, mid+1, end, k);
  }
  return -1;
}

int search(vector<int> &nums, int target) {
    int ans = b_search(nums, 0, nums.size()-1, target);
    return ans;
}
