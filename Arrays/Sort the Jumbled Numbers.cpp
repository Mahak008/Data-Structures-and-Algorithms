// Leetcode - 2191

string getMaapedStr(string& num, vector<int>& mapping) {
    string mappedNum = "";

    for (int i = 0; i < num.length(); i++) {
        char ch = num[i];
        mappedNum += to_string(mapping[ch - '0']);
    }

    return mappedNum;
}

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

// Alternate Approach

int getMappedNum(int num, vector<int>& mapping) {
    if (num < 10) {
        return mapping[num];
    }

    int mappedNum = 0;
    int placeValue = 1;

    while (num) {
        int lastDigit = num % 10;
        int mappedDigit = mapping[lastDigit];
        mappedNum += (mappedDigit * placeValue);
        placeValue *= 10;
        num /= 10;
    }

    return mappedNum;
}

vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
    int n = nums.size();
    vector<pair<int, int>> temp;

    for (int i = 0; i < n; i++) {
        int mappedNum = getMappedNum(nums[i], mapping);
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
