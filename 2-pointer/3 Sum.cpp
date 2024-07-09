vector<vector<int>> threeSum(vector<int>& nums) {
  sort(nums.begin(), nums.end());
  vector<vector<int>> ans;
  
  for(int i = 0; i < nums.size(); i++) {
    if(i > 0 && nums[i] == nums[i-1]) {
      continue;
    }
    
    int j = i+1;
    int k = nums.size()-1;
    
    while(j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if(sum < 0) {
        j++;
      }
        
      else if(sum > 0) {
        k--;
      }
        
      else {
        vector <int> num = {nums[i], nums[j], nums[k]};
        ans.push_back(num);
        j++;
        k--;
        
        while(j < k && nums[j] == nums[j-1]) {
          j++;
        }
        
        while(j < k && nums[k] == nums[k+1]) {
          k--;
        }
      }
    }
  }
  
  return ans;
}

// Input : -1,0,1,2,-1,-4
// Output : 
// -1,-1,2
// -1,0,1
