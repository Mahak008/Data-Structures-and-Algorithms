// Given an array arr[] and an integer k where k is smaller than the size of the array, the task is to find the kth smallest element in the given array. It is given that all array elements are distinct.
// Note:-  l and r denotes the starting and ending index of the array.

int kthSmallest(int arr[], int l, int r, int k) {
  priority_queue<int, vector<int>, greater<int>> pq;
  int ans;
        
  for(int i = l; i <= r; i++) {
    pq.push(arr[i]);
  }
        
  while(k--) {
    ans = pq.top();
    pq.pop();
  }
  return ans;
}

// Input:
// n = 6
// arr[] = 7 10 4 3 20 15
// k = 3
// l=0 r=5

// Output : 
// 7
