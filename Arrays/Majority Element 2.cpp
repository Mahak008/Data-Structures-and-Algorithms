vector<int> majorityElement(vector<int>& nums) {
  int el1, el2;
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(cnt1 == 0  && el2 != nums[i]) {
      el1 = nums[i];
      cnt1 = 1;
    }
    else if(cnt2 == 0 && el1 != nums[i]) {
      el2 = nums[i];
      cnt2 = 1;
    }
    else if(nums[i] == el1) {
      cnt1++;
    }
    else if(nums[i] == el2) {
      cnt2++;
    }
    else {
      cnt1--;
      cnt2--;
    }
  }
  vector <int> ans;
  int c1 = 0, c2 = 0;
  for(int i = 0; i < nums.size(); i++) {
    if(el1 == nums[i]) {
      c1++;
    }
    else if(el2 == nums[i]) {
      c2++;
    }
  }
  if(c1 > nums.size()/3) {
    ans.push_back(el1);
  }
  if(c2 > nums.size()/3) {
    ans.push_back(el2);
  }
  return ans;
}

// Input : 3,2,3
// Output : 3
