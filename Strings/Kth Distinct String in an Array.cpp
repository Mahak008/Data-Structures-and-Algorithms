// Leetcode - 2053

string kthDistinct(vector<string>& arr, int k) {
    unordered_map<string, int> mp;

    for (string s : arr) {
        mp[s]++;
    }

    for (auto it : arr) {
        if (mp[it] == 1) {
            --k;
            if (k == 0) {
                return it;
            }
        }
    }

    return "";
}

// Input: arr = ["d","b","c","b","c","a"], k = 2
// Output: "a"
