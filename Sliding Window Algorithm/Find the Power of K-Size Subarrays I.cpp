vector<int> resultsArray(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
  
    for (int i = 0; i <= n - k; ++i) {
        vector<int> sub(nums.begin() + i, nums.begin() + i + k);
        bool con = true;
      
        for (int j = 1; j < k; ++j) {
            if (sub[j] != sub[j - 1] + 1) {
                con = false;
                break;
            }
        }

        if (con) {
            ans.push_back(*max_element(sub.begin(), sub.end()));
        } else {
            ans.push_back(-1);
        }
    }
    return ans;
}

// Input: nums = [1,2,3,4,3,2,5], k = 3
// Output: [3,4,-1,-1,-1]
