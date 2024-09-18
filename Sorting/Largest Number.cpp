// Leetcode - 179

static bool comp(int a, int b) {
    return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), comp);

    if (nums[0] == 0) {
        return "0";
    }

    string num = "";
    for (int n : nums) {
        num += to_string(n);
    }

    return num;
}

// Input: nums = [3,30,34,5,9]
// Output: "9534330"
