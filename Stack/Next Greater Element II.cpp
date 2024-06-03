// Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
// The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

vector<int> nextGreaterElements(vector<int>& nums) {
  stack<int>st;
  vector <int> ans;
  int n = nums.size();
  
  for(int i = 2*n-1; i >= 0; i--) {
    while(!st.empty() && st.top() <= nums[i%n]) {
      st.pop();
    }
    if(i < n) {
      if(st.empty()) {
        ans.emplace_back(-1);
      }
      else {
        ans.emplace_back(st.top());
      }
    }
    st.push(nums[i%n]);
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

// nums = [100,1,11,1,120,111,123,1,-1,-100]
// Output : [120,11,120,120,123,123,-1,100,100,100]
