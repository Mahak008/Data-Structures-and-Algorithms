class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMostK(nums, k) - atMostK(nums, k - 1);
    }
    
    int atMostK(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, count = 0, result = 0;
        
        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0) {
                count++;
            }
            
            while (count > k) {
                if (nums[left] % 2 != 0) {
                    count--;
                }
                left++;
            }
            
            result += right - left + 1;
        }
        return result;
    }
};
