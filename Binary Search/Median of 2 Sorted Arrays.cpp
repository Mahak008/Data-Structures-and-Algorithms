// Brute Force Approach

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  vector<int> arr;
  int i = 0, j = 0;
  while(i < nums1.size() && j < nums2.size()) {
    if(nums1[i] < nums2[j]) {
      arr.push_back(nums1[i]);
      i++;
    }
    else {
      arr.push_back(nums2[j]);
      j++;
    }
  }
  while(i < nums1.size()) {
    arr.push_back(nums1[i]);
  }
  while(j < nums2.size()) {
    arr.push_back(nums2[j]);
  }

  if(arr.size() % 2 != 0) {
    return arr[arr.size()/2];
  }
  return (double)((double)(arr[arr.size()/2]) + (double) (arr[arr.size()/2+1]))/2.0;
}

// Binary Search Approach
