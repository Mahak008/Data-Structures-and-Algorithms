int minKBitFlips(vector<int>& nums, int k) {
    int flip = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 0) {
            if (i + k - 1 >= nums.size()) {
                return -1;
            }

            for (int j = i; j <= i + k - 1; j++) {
                nums[j] = !nums[j];
            }
            flip += 1;
        }
    }
    return flip;
}
