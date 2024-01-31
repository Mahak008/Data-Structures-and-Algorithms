int removeDuplicates(vector<int>& nums) {
  int j = 1;
  for(int i = 0; i < nums.size()-1; i++) {
    if(nums[i] != nums[i+1]) {
      nums[j] = nums[i+1];
      j++;
    }
  }
  return j;
}

// OR

int removeDuplicates(vector<int>& nums) {
  int j = 1;
  for(int i = 1; i < nums.size(); i++) {
    if(nums[i] != nums[i-1]) {
      nums[j] = nums[i];
      j++;
    }
  }
  return j;
}

// Input - [1, 1, 2]
// Output - [1,2]
