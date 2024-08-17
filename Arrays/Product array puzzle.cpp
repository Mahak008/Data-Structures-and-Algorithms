vector<long long int> productExceptSelf(vector<long long int>& nums) {
    int n = nums.size();
    vector<long long int> result(n, 1);
  
    long long int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }
    
    long long int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }
        
    return result;
}

// Input: nums[] = [10, 3, 5, 6, 2]
// Output: [180, 600, 360, 300, 900]
