vector<int> twoSum(vector<int>& nums, int target) {
  vector <int> v;
  map<int,int>mp;
  for(int i = 0; i < nums.size(); i++) {
    int x = nums[i];
    int rem = target - x;
    if(mp.find(rem) != mp.end()) {
      v.push_back(mp[rem]);
      v.push_back(i);
    }
    else {
      mp[x] = i;
    }
  }
  return v;
}

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
