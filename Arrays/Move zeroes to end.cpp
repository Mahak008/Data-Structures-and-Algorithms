int j = -1;
int n = nums.size();
for(int i = 0; i < n; i++) {
  if(nums[i] == 0) {
    j = i;
    break;
  }
}
if(j != -1) {
  for(int i = j+1; i < n; i++) {
    if(nums[i] != 0) {
      swap(nums[i], nums[j]);
      j++;
    }
  }
}

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
