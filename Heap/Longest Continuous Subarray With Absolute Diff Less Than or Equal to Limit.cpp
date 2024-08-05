// Leetcode - 1438

typedef pair<int, int> P;
    
int longestSubarray(vector<int>& nums, int limit) {
  int n = nums.size();
  priority_queue<P, vector<P>> maxPq; //max-heap
  priority_queue<P, vector<P>, greater<P>> minPq; //min-heap

  int i = 0, j = 0, maxLength = 0;
  
  while(j < n) {
    maxPq.push({nums[j], j});
    minPq.push({nums[j], j});

    while(maxPq.top().first - minPq.top().first > limit) {
      i = min(maxPq.top().second, minPq.top().second) + 1;

      while(maxPq.top().second < i) {
        maxPq.pop();
      }

      while(minPq.top().second < i) {
        minPq.pop();
      }
    }
    maxLength = max(maxLength, j - i + 1);
    j++;
  }
  return maxLength;
}

// Input: nums = [4,2,2,2,4,4,2,2], limit = 0
// Output: 3
