// Leetcode - 2191

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> temp;

    for (int i = 0; i < n; i++) {
        string num = to_string(nums[i]);
        string mappedStr = getMaapedStr(num, mapping);
        int mappedNum = stoi(mappedStr);
        temp.push_back({mappedNum, i});
    }

    sort(temp.begin(), temp.end());

    vector<int> ans;
    for (auto it : temp) {
        ans.push_back(nums[it.second]);
    }

    return ans;
}

// Input: mapping = [8,9,4,0,2,1,3,5,7,6], nums = [991,338,38]
// Output: [338,38,991]
