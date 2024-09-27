vector<int> maxSlidingWindow(vector<int>& nums, int k, int n) {
  deque<int> dq;
  vector<int> ans;
  int r = 0;
  
  while(r < n) {
    if (!dq.empty() && dq.front() == (r-k)) {
      dq.pop_front();
    }
  
    while (!dq.empty() && nums[dq.back()] < nums[r]) {
      dq.pop_back();
    }
    
    dq.push_back(r);
    
    if (r >= (k-1)) {
      ans.push_back(nums[dq.front()]);
    }

    ++r;
  }  
  return ans;
}

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
