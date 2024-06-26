typedef pair<int, int> p;
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> mp;

    for (int i = 0; i < nums.size(); i++) {
        mp[nums[i]]++;
    }

    priority_queue<p> pq;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        pq.push({it->second, it->first});
    }

    vector<int> ans;
    while (k-- && !pq.empty()) {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
