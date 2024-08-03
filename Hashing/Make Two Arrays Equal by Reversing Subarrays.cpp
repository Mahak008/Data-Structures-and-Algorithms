// Leetcode - 1460

bool canBeEqual(vector<int>& target, vector<int>& arr) {
    map<int, int> mp;
    for (int i = 0; i < target.size(); i++) {
        mp[target[i]]++;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (mp.find(arr[i]) != mp.end()) {
            mp[arr[i]]--;
        }
        if (mp[arr[i]] == 0) {
            mp.erase(arr[i]);
        }
    }

    if (mp.empty()) {
        return true;
    }

    return false;
}

// Input: target = [3,7,9], arr = [3,7,11]
// Output: false
// Explanation: arr does not have value 9 and it can never be converted to target.
